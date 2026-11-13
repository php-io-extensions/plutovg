/*
 * Value structs, handle objects and argument checks shared by the binding's files.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>

#include "php.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"
#include "runtime.h"
#include "../stubs/plutovg_structs_arginfo.h"
#include "../stubs/plutovg_constants_arginfo.h"

zend_class_entry *pv_surface_ce, *pv_paint_ce, *pv_canvas_ce, *pv_font_face_ce, *pv_font_face_cache_ce;
zend_class_entry *pv_point_ce, *pv_rect_ce, *pv_matrix_ce, *pv_color_ce, *pv_gradient_stop_ce,
	*pv_path_element_header_ce, *pv_path_element_ce, *pv_path_ce, *pv_path_iterator_ce, *pv_text_iterator_ce;

static zend_object_handlers pv_handle_handlers;
static zend_object_handlers pv_path_handlers, pv_path_iterator_handlers, pv_text_iterator_handlers;

/* ---- value structs ------------------------------------------------------------------------- */

/* Property i (declaration order) of a struct object as a float; an unset property reads as 0. */
static float pv_float(zend_object *o, uint32_t i)
{
	zval *v = OBJ_PROP_NUM(o, i);
	ZVAL_DEREF(v);
	return Z_TYPE_P(v) == IS_DOUBLE ? (float) Z_DVAL_P(v) : 0.0f;
}

static void pv_set_float(zend_object *o, const char *name, float value)
{
	zend_update_property_double(o->ce, o, name, strlen(name), (double) value);
}

/* Property i as an object of `ce`, or NULL. */
static zend_object *pv_sub(zend_object *o, uint32_t i, zend_class_entry *ce)
{
	zval *v = OBJ_PROP_NUM(o, i);
	ZVAL_DEREF(v);
	return Z_TYPE_P(v) == IS_OBJECT && instanceof_function(Z_OBJCE_P(v), ce) ? Z_OBJ_P(v) : NULL;
}

void pv_point_read(zend_object *o, plutovg_point_t *out) { out->x = pv_float(o, 0); out->y = pv_float(o, 1); }

void pv_point_write(zend_object *o, const plutovg_point_t *in) { pv_set_float(o, "x", in->x); pv_set_float(o, "y", in->y); }

void pv_point_new(const plutovg_point_t *in, zval *out)
{
	object_init_ex(out, pv_point_ce);
	pv_point_write(Z_OBJ_P(out), in);
}

void pv_rect_read(zend_object *o, plutovg_rect_t *out)
{
	out->x = pv_float(o, 0); out->y = pv_float(o, 1); out->w = pv_float(o, 2); out->h = pv_float(o, 3);
}

void pv_rect_write(zend_object *o, const plutovg_rect_t *in)
{
	pv_set_float(o, "x", in->x); pv_set_float(o, "y", in->y); pv_set_float(o, "w", in->w); pv_set_float(o, "h", in->h);
}

void pv_matrix_read(zend_object *o, plutovg_matrix_t *out)
{
	out->a = pv_float(o, 0); out->b = pv_float(o, 1); out->c = pv_float(o, 2);
	out->d = pv_float(o, 3); out->e = pv_float(o, 4); out->f = pv_float(o, 5);
}

void pv_matrix_write(zend_object *o, const plutovg_matrix_t *in)
{
	pv_set_float(o, "a", in->a); pv_set_float(o, "b", in->b); pv_set_float(o, "c", in->c);
	pv_set_float(o, "d", in->d); pv_set_float(o, "e", in->e); pv_set_float(o, "f", in->f);
}

void pv_color_read(zend_object *o, plutovg_color_t *out)
{
	out->r = pv_float(o, 0); out->g = pv_float(o, 1); out->b = pv_float(o, 2); out->a = pv_float(o, 3);
}

void pv_color_write(zend_object *o, const plutovg_color_t *in)
{
	pv_set_float(o, "r", in->r); pv_set_float(o, "g", in->g); pv_set_float(o, "b", in->b); pv_set_float(o, "a", in->a);
}

void pv_gradient_stop_read(zend_object *o, plutovg_gradient_stop_t *out)
{
	out->offset = pv_float(o, 0);
	zend_object *color = pv_sub(o, 1, pv_color_ce);
	if (color) {
		pv_color_read(color, &out->color);
	} else {
		memset(&out->color, 0, sizeof(out->color));
	}
}

bool pv_points_read(HashTable *arr, zend_long count, plutovg_point_t *out, uint32_t arg_num)
{
	if (count < 0 || count > zend_hash_num_elements(arr)) {
		zend_argument_value_error(arg_num, "must hold at least the %s count of points (" ZEND_LONG_FMT " given, %u held)",
			count < 0 ? "non-negative" : "given", count, zend_hash_num_elements(arr));
		return false;
	}
	zend_long i = 0;
	zval *v;
	ZEND_HASH_FOREACH_VAL(arr, v) {
		if (i == count) {
			break;
		}
		ZVAL_DEREF(v);
		if (Z_TYPE_P(v) != IS_OBJECT || Z_OBJCE_P(v) != pv_point_ce) {
			zend_argument_type_error(arg_num, "must be a list of plutovg_point, %s found at position " ZEND_LONG_FMT, zend_zval_type_name(v), i);
			return false;
		}
		pv_point_read(Z_OBJ_P(v), &out[i++]);
	} ZEND_HASH_FOREACH_END();
	return true;
}

/* Every struct constructor: its float arguments land in its properties in order. */
static void pv_construct_floats(INTERNAL_FUNCTION_PARAMETERS, uint32_t n)
{
	double v[6] = {0};
	if (zend_parse_parameters(ZEND_NUM_ARGS(), n == 2 ? "|dd" : n == 4 ? "|dddd" : "|dddddd",
			&v[0], &v[1], &v[2], &v[3], &v[4], &v[5]) == FAILURE) {
		RETURN_THROWS();
	}
	zend_object *o = Z_OBJ_P(ZEND_THIS);
	zend_property_info *info;
	uint32_t i = 0;
	ZEND_HASH_MAP_FOREACH_PTR(&o->ce->properties_info, info) {
		if (i < n) {
			zend_update_property_double(o->ce, o, ZSTR_VAL(info->name), ZSTR_LEN(info->name), v[i++]);
		}
	} ZEND_HASH_FOREACH_END();
}

ZEND_METHOD(plutovg_point, __construct) { pv_construct_floats(INTERNAL_FUNCTION_PARAM_PASSTHRU, 2); }
ZEND_METHOD(plutovg_rect, __construct) { pv_construct_floats(INTERNAL_FUNCTION_PARAM_PASSTHRU, 4); }
ZEND_METHOD(plutovg_matrix, __construct) { pv_construct_floats(INTERNAL_FUNCTION_PARAM_PASSTHRU, 6); }
ZEND_METHOD(plutovg_color, __construct) { pv_construct_floats(INTERNAL_FUNCTION_PARAM_PASSTHRU, 4); }

ZEND_METHOD(plutovg_gradient_stop, __construct)
{
	double offset = 0;
	zend_object *color = NULL;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(offset)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(color, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	zend_object *o = Z_OBJ_P(ZEND_THIS);
	zend_update_property_double(o->ce, o, "offset", sizeof("offset") - 1, offset);
	if (color) {
		zval z;
		ZVAL_OBJ(&z, color);
		zend_update_property(o->ce, o, "color", sizeof("color") - 1, &z);
	}
}

ZEND_METHOD(plutovg_path_element_header, __construct)
{
	zend_long command = 0, length = 0;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(command)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	zend_object *o = Z_OBJ_P(ZEND_THIS);
	zend_update_property_long(o->ce, o, "command", sizeof("command") - 1, command);
	zend_update_property_long(o->ce, o, "length", sizeof("length") - 1, length);
}

ZEND_METHOD(plutovg_path_element, __construct)
{
	zend_object *header = NULL, *point = NULL;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(header, pv_path_element_header_ce)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(point, pv_point_ce)
	ZEND_PARSE_PARAMETERS_END();
	zend_object *o = Z_OBJ_P(ZEND_THIS);
	zval z;
	if (header) {
		ZVAL_OBJ(&z, header);
		zend_update_property(o->ce, o, "header", sizeof("header") - 1, &z);
	}
	if (point) {
		ZVAL_OBJ(&z, point);
		zend_update_property(o->ce, o, "point", sizeof("point") - 1, &z);
	}
}

/* ---- paths ----------------------------------------------------------------------------------- */

ZEND_METHOD(plutovg_path, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

static zend_object *pv_path_create(zend_class_entry *ce)
{
	pv_path_obj *p = zend_object_alloc(sizeof(pv_path_obj), ce);
	p->path = NULL;
	zend_object_std_init(&p->std, ce);
	object_properties_init(&p->std, ce);
	p->std.handlers = &pv_path_handlers;
	return &p->std;
}

static void pv_path_free(zend_object *o)
{
	pv_path_obj *p = pv_path_from(o);
	if (p->path) {
		plutovg_path_destroy(p->path);
		p->path = NULL;
	}
	zend_object_std_dtor(o);
}

plutovg_path_t *pv_path_arg(zval *zv, uint32_t arg_num)
{
	pv_path_obj *p = pv_path_from(Z_OBJ_P(zv));
	if (!p->path) {
		zend_argument_value_error(arg_num, "is a plutovg_path already released by plutovg_path_destroy()");
		return NULL;
	}
	return p->path;
}

void pv_path_wrap(plutovg_path_t *path, zval *out)
{
	if (!path) {
		ZVAL_NULL(out);
		return;
	}
	object_init_ex(out, pv_path_ce);
	pv_path_from(Z_OBJ_P(out))->path = path;
}

/* ---- surfaces, paints, canvases, font faces, caches ------------------------------------------ */

ZEND_METHOD(plutovg_surface, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }
ZEND_METHOD(plutovg_paint, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }
ZEND_METHOD(plutovg_canvas, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }
ZEND_METHOD(plutovg_font_face, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }
ZEND_METHOD(plutovg_font_face_cache, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

static zend_object *pv_handle_create(zend_class_entry *ce)
{
	pv_handle_obj *h = zend_object_alloc(sizeof(pv_handle_obj), ce);
	h->ptr = NULL;
	h->keep = NULL;
	zend_object_std_init(&h->std, ce);
	object_properties_init(&h->std, ce);
	h->std.handlers = &pv_handle_handlers;
	return &h->std;
}

void pv_handle_release(zend_object *o)
{
	pv_handle_obj *h = pv_handle_from(o);
	void *ptr = h->ptr;
	h->ptr = NULL;
	if (!ptr) {
		return;
	}
	if (o->ce == pv_surface_ce) {
		plutovg_surface_destroy(ptr);
	} else if (o->ce == pv_paint_ce) {
		plutovg_paint_destroy(ptr);
	} else if (o->ce == pv_canvas_ce) {
		plutovg_canvas_destroy(ptr);
	} else if (o->ce == pv_font_face_ce) {
		plutovg_font_face_destroy(ptr);
	} else {
		plutovg_font_face_cache_destroy(ptr);
	}
}

static void pv_handle_free(zend_object *o)
{
	pv_handle_obj *h = pv_handle_from(o);
	/* The C reference goes first: the memory in keep may be what it draws into. */
	pv_handle_release(o);
	if (h->keep) {
		zend_array_destroy(h->keep);
		h->keep = NULL;
	}
	zend_object_std_dtor(o);
}

static HashTable *pv_handle_gc(zend_object *o, zval **table, int *n)
{
	pv_handle_obj *h = pv_handle_from(o);
	if (h->keep) {
		*table = NULL;
		*n = 0;
		zend_get_gc_buffer *buf = zend_get_gc_buffer_create();
		zval *v;
		ZEND_HASH_FOREACH_VAL(h->keep, v) {
			zend_get_gc_buffer_add_zval(buf, v);
		} ZEND_HASH_FOREACH_END();
		zend_get_gc_buffer_use(buf, table, n);
	} else {
		*table = NULL;
		*n = 0;
	}
	return zend_std_get_properties(o);
}

void *pv_handle_arg(zval *zv, uint32_t arg_num)
{
	pv_handle_obj *h = pv_handle_from(Z_OBJ_P(zv));
	if (!h->ptr) {
		zend_argument_value_error(arg_num, "is a %s already released by its destroy function", ZSTR_VAL(Z_OBJCE_P(zv)->name));
		return NULL;
	}
	return h->ptr;
}

void pv_handle_keep(zend_object *to, zend_object *from, zval *value)
{
	pv_handle_obj *t = pv_handle_from(to);
	if ((!from || !pv_handle_from(from)->keep) && !value) {
		return;
	}
	if (!t->keep) {
		t->keep = zend_new_array(1);
	}
	if (from && pv_handle_from(from)->keep) {
		zval *v;
		ZEND_HASH_FOREACH_VAL(pv_handle_from(from)->keep, v) {
			Z_TRY_ADDREF_P(v);
			zend_hash_next_index_insert(t->keep, v);
		} ZEND_HASH_FOREACH_END();
	}
	if (value) {
		Z_TRY_ADDREF_P(value);
		zend_hash_next_index_insert(t->keep, value);
	}
}

void pv_handle_wrap(zend_class_entry *ce, void *ptr, zend_object *from, zval *out)
{
	if (!ptr) {
		ZVAL_NULL(out);
		return;
	}
	object_init_ex(out, ce);
	pv_handle_from(Z_OBJ_P(out))->ptr = ptr;
	pv_handle_keep(Z_OBJ_P(out), from, NULL);
}

/* ---- iterators ------------------------------------------------------------------------------- */

ZEND_METHOD(plutovg_path_iterator, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }
ZEND_METHOD(plutovg_text_iterator, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

static zend_object *pv_path_iterator_create(zend_class_entry *ce)
{
	pv_path_iterator_obj *it = zend_object_alloc(sizeof(pv_path_iterator_obj), ce);
	memset(&it->it, 0, sizeof(it->it));
	it->path = NULL;
	it->elements = NULL;
	it->size = 0;
	zend_object_std_init(&it->std, ce);
	object_properties_init(&it->std, ce);
	it->std.handlers = &pv_path_iterator_handlers;
	return &it->std;
}

static void pv_path_iterator_free(zend_object *o)
{
	pv_path_iterator_obj *it = pv_path_iterator_from(o);
	if (it->path) {
		OBJ_RELEASE(it->path);
		it->path = NULL;
	}
	zend_object_std_dtor(o);
}

/* The iterator's path for the GC: it holds a reference to that object. */
static HashTable *pv_path_iterator_gc(zend_object *o, zval **table, int *n)
{
	pv_path_iterator_obj *it = pv_path_iterator_from(o);
	zend_get_gc_buffer *buf = zend_get_gc_buffer_create();
	if (it->path) {
		zend_get_gc_buffer_add_obj(buf, it->path);
	}
	zend_get_gc_buffer_use(buf, table, n);
	return zend_std_get_properties(o);
}

static zend_object *pv_text_iterator_create(zend_class_entry *ce)
{
	pv_text_iterator_obj *it = zend_object_alloc(sizeof(pv_text_iterator_obj), ce);
	memset(&it->it, 0, sizeof(it->it));
	it->text = NULL;
	zend_object_std_init(&it->std, ce);
	object_properties_init(&it->std, ce);
	it->std.handlers = &pv_text_iterator_handlers;
	return &it->std;
}

static void pv_text_iterator_free(zend_object *o)
{
	pv_text_iterator_obj *it = pv_text_iterator_from(o);
	if (it->text) {
		zend_string_release(it->text);
		it->text = NULL;
	}
	zend_object_std_dtor(o);
}

/* ---- argument checks ------------------------------------------------------------------------- */

/* PlutoVG's float dasher: once dist1 is large against a dash, dist1 + dash == dist1 and it never returns. */
#define PV_MAX_DASHES (1 << 22)

bool pv_dashes(HashTable *dashes, zend_long ndashes, const plutovg_path_t *path, float **out, uint32_t arg_num)
{
	*out = NULL;
	if (ndashes < 0 || ndashes > zend_hash_num_elements(dashes)) {
		zend_argument_value_error(arg_num, "must be between 0 and the number of dashes given (%u)", zend_hash_num_elements(dashes));
		return false;
	}
	if (ndashes == 0) {
		return true;
	}
	float *d = safe_emalloc(ndashes, sizeof(float), 0);
	float sum = 0.0f, smallest = INFINITY;
	zend_long i = 0;
	zval *v;
	ZEND_HASH_FOREACH_VAL(dashes, v) {
		if (i == ndashes) {
			break;
		}
		ZVAL_DEREF(v);
		if (Z_TYPE_P(v) != IS_DOUBLE && Z_TYPE_P(v) != IS_LONG) {
			efree(d);
			zend_argument_type_error(arg_num - 1, "must be a list of floats, %s found at position " ZEND_LONG_FMT, zend_zval_type_name(v), i);
			return false;
		}
		float f = (float) zval_get_double(v);
		if (!isfinite(f) || f < 0.0f) {
			efree(d);
			zend_argument_value_error(arg_num - 1, "must hold finite, non-negative dash lengths (position " ZEND_LONG_FMT ")", i);
			return false;
		}
		d[i++] = f;
		sum += f;
		if (f > 0.0f && f < smallest) {
			smallest = f;
		}
	} ZEND_HASH_FOREACH_END();
	if (path && sum > 0.0f) {
		float length = plutovg_path_length(path);
		if (!isfinite(length) || (double) length / smallest > (double) PV_MAX_DASHES) {
			efree(d);
			zend_argument_value_error(arg_num - 1, "would split the path into more than %d dashes (path length %g, shortest dash %g)",
				PV_MAX_DASHES, (double) length, (double) smallest);
			return false;
		}
	}
	(void) sum;
	*out = d;
	return true;
}

bool pv_dash_bound(const float *dashes, int ndashes, const plutovg_path_t *path, const char *what)
{
	float sum = 0.0f, smallest = INFINITY;
	for (int i = 0; i < ndashes; i++) {
		sum += dashes[i];
		if (dashes[i] > 0.0f && dashes[i] < smallest) {
			smallest = dashes[i];
		}
	}
	if (sum <= 0.0f) {
		return true;
	}
	float length = plutovg_path_length(path);
	if (!isfinite(length) || (double) length / smallest > (double) PV_MAX_DASHES) {
		zend_value_error("%s: the canvas's dash array would split the path into more than %d dashes (path length %g, shortest dash %g)",
			what, PV_MAX_DASHES, (double) length, (double) smallest);
		return false;
	}
	return true;
}

bool pv_stops(HashTable *stops, zend_long nstops, plutovg_gradient_stop_t **out, uint32_t arg_num)
{
	*out = NULL;
	if (nstops < 0 || nstops > zend_hash_num_elements(stops)) {
		zend_argument_value_error(arg_num, "must be between 0 and the number of stops given (%u)", zend_hash_num_elements(stops));
		return false;
	}
	if (nstops == 0) {
		return true;
	}
	plutovg_gradient_stop_t *s = safe_emalloc(nstops, sizeof(plutovg_gradient_stop_t), 0);
	zend_long i = 0;
	zval *v;
	ZEND_HASH_FOREACH_VAL(stops, v) {
		if (i == nstops) {
			break;
		}
		ZVAL_DEREF(v);
		if (Z_TYPE_P(v) != IS_OBJECT || Z_OBJCE_P(v) != pv_gradient_stop_ce) {
			efree(s);
			zend_argument_type_error(arg_num - 1, "must be a list of plutovg_gradient_stop, %s found at position " ZEND_LONG_FMT, zend_zval_type_name(v), i);
			return false;
		}
		pv_gradient_stop_read(Z_OBJ_P(v), &s[i++]);
	} ZEND_HASH_FOREACH_END();
	*out = s;
	return true;
}

bool pv_enum(zend_long value, zend_long max, const char *prefix, uint32_t arg_num)
{
	if (value < 0 || value > max) {
		zend_argument_value_error(arg_num, "must be a %s* constant", prefix);
		return false;
	}
	return true;
}

bool pv_codepoint(zend_long value, uint32_t arg_num)
{
	if (value < 0 || value > 0xFFFFFFFF) {
		zend_argument_value_error(arg_num, "must be between 0 and 0xFFFFFFFF");
		return false;
	}
	return true;
}

bool pv_length(zend_string *s, zend_long length, uint32_t arg_num)
{
	if (length < -1 || length > (zend_long) ZSTR_LEN(s) || length > INT_MAX) {
		zend_argument_value_error(arg_num, "must be -1 or between 0 and the string's length (%zu)", ZSTR_LEN(s));
		return false;
	}
	return true;
}

bool pv_text(zend_string *s, zend_long length, zend_long encoding, int *units, uint32_t arg_num)
{
	size_t unit;
	switch (encoding) {
		case PLUTOVG_TEXT_ENCODING_LATIN1:
		case PLUTOVG_TEXT_ENCODING_UTF8: unit = 1; break;
		case PLUTOVG_TEXT_ENCODING_UTF16: unit = 2; break;
		case PLUTOVG_TEXT_ENCODING_UTF32: unit = 4; break;
		default:
			zend_argument_value_error(arg_num + 1, "must be a PLUTOVG_TEXT_ENCODING_* constant");
			return false;
	}
	size_t held = ZSTR_LEN(s) / unit;
	if (held > INT_MAX) {
		zend_argument_value_error(arg_num - 1, "is longer than PlutoVG can count (INT_MAX units)");
		return false;
	}
	if (length == -1) {
		const char *p = ZSTR_VAL(s);
		size_t n = 0;
		for (; n < held; n++) {
			uint32_t u = unit == 1 ? (uint8_t) p[n] : unit == 2 ? ((const uint16_t *) p)[n] : ((const uint32_t *) p)[n];
			if (u == 0) {
				break;
			}
		}
		*units = (int) n;
		return true;
	}
	if (length < -1 || (size_t) length > held) {
		zend_argument_value_error(arg_num, "must be -1 or between 0 and the string's length in units (%zu)", held);
		return false;
	}
	*units = (int) length;
	return true;
}

/* ---- registration ---------------------------------------------------------------------------- */

void pv_runtime_minit(int module_number)
{
	register_plutovg_constants_symbols(module_number);

	pv_point_ce = register_class_plutovg_point();
	pv_rect_ce = register_class_plutovg_rect();
	pv_matrix_ce = register_class_plutovg_matrix();
	pv_color_ce = register_class_plutovg_color();
	pv_gradient_stop_ce = register_class_plutovg_gradient_stop();
	pv_path_element_header_ce = register_class_plutovg_path_element_header();
	pv_path_element_ce = register_class_plutovg_path_element();

	memcpy(&pv_handle_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	pv_handle_handlers.offset = XtOffsetOf(pv_handle_obj, std);
	pv_handle_handlers.free_obj = pv_handle_free;
	pv_handle_handlers.get_gc = pv_handle_gc;
	pv_handle_handlers.clone_obj = NULL;
	zend_class_entry **handles[] = { &pv_surface_ce, &pv_paint_ce, &pv_canvas_ce, &pv_font_face_ce, &pv_font_face_cache_ce };
	pv_surface_ce = register_class_plutovg_surface();
	pv_paint_ce = register_class_plutovg_paint();
	pv_canvas_ce = register_class_plutovg_canvas();
	pv_font_face_ce = register_class_plutovg_font_face();
	pv_font_face_cache_ce = register_class_plutovg_font_face_cache();
	for (size_t i = 0; i < sizeof(handles) / sizeof(handles[0]); i++) {
		(*handles[i])->create_object = pv_handle_create;
	}

	pv_path_ce = register_class_plutovg_path();
	pv_path_ce->create_object = pv_path_create;
	memcpy(&pv_path_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	pv_path_handlers.offset = XtOffsetOf(pv_path_obj, std);
	pv_path_handlers.free_obj = pv_path_free;
	pv_path_handlers.clone_obj = NULL;

	pv_path_iterator_ce = register_class_plutovg_path_iterator();
	pv_path_iterator_ce->create_object = pv_path_iterator_create;
	memcpy(&pv_path_iterator_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	pv_path_iterator_handlers.offset = XtOffsetOf(pv_path_iterator_obj, std);
	pv_path_iterator_handlers.free_obj = pv_path_iterator_free;
	pv_path_iterator_handlers.get_gc = pv_path_iterator_gc;
	pv_path_iterator_handlers.clone_obj = NULL;

	pv_text_iterator_ce = register_class_plutovg_text_iterator();
	pv_text_iterator_ce->create_object = pv_text_iterator_create;
	memcpy(&pv_text_iterator_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	pv_text_iterator_handlers.offset = XtOffsetOf(pv_text_iterator_obj, std);
	pv_text_iterator_handlers.free_obj = pv_text_iterator_free;
	pv_text_iterator_handlers.clone_obj = NULL;
}
