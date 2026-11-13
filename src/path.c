/*
 * Matrices, paths, path and text iterators: plutovg.h from plutovg_matrix_init to
 * plutovg_text_iterator_next. Every function written out.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>

#include "php.h"
#include "zend_exceptions.h"
#include "runtime.h"
#include "../stubs/plutovg_path_arginfo.h"

void pv_path_minit(void) { zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT); }

/* A matrix argument's value, and writing a result back into it. */
#define MATRIX_IN(zv, m) plutovg_matrix_t m; pv_matrix_read(Z_OBJ_P(zv), &m)
#define MATRIX_OUT(zv, m) pv_matrix_write(Z_OBJ_P(zv), &m)

/* ---- matrices -------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_matrix_init)
{
	zval *zm;
	double a, b, c, d, e, f;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(a) Z_PARAM_DOUBLE(b) Z_PARAM_DOUBLE(c)
		Z_PARAM_DOUBLE(d) Z_PARAM_DOUBLE(e) Z_PARAM_DOUBLE(f)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init(&m, (float) a, (float) b, (float) c, (float) d, (float) e, (float) f);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_init_identity)
{
	zval *zm;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init_identity(&m);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_init_translate)
{
	zval *zm;
	double tx, ty;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(tx) Z_PARAM_DOUBLE(ty)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init_translate(&m, (float) tx, (float) ty);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_init_scale)
{
	zval *zm;
	double sx, sy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(sx) Z_PARAM_DOUBLE(sy)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init_scale(&m, (float) sx, (float) sy);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_init_rotate)
{
	zval *zm;
	double angle;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(angle)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init_rotate(&m, (float) angle);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_init_shear)
{
	zval *zm;
	double shx, shy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(shx) Z_PARAM_DOUBLE(shy)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_matrix_t m;
	plutovg_matrix_init_shear(&m, (float) shx, (float) shy);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_translate)
{
	zval *zm;
	double tx, ty;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(tx) Z_PARAM_DOUBLE(ty)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_matrix_translate(&m, (float) tx, (float) ty);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_scale)
{
	zval *zm;
	double sx, sy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(sx) Z_PARAM_DOUBLE(sy)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_matrix_scale(&m, (float) sx, (float) sy);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_rotate)
{
	zval *zm;
	double angle;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(angle)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_matrix_rotate(&m, (float) angle);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_shear)
{
	zval *zm;
	double shx, shy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(shx) Z_PARAM_DOUBLE(shy)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_matrix_shear(&m, (float) shx, (float) shy);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_multiply)
{
	zval *zm, *zl, *zr;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_OBJECT_OF_CLASS(zl, pv_matrix_ce)
		Z_PARAM_OBJECT_OF_CLASS(zr, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zl, left);
	MATRIX_IN(zr, right);
	plutovg_matrix_t m;
	plutovg_matrix_multiply(&m, &left, &right);
	MATRIX_OUT(zm, m);
}

ZEND_FUNCTION(plutovg_matrix_invert)
{
	zval *zm, *zi;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zi, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_matrix_t inverse;
	bool ok = plutovg_matrix_invert(&m, zi ? &inverse : NULL);
	if (ok && zi) {
		MATRIX_OUT(zi, inverse);
	}
	RETURN_BOOL(ok);
}

ZEND_FUNCTION(plutovg_matrix_map)
{
	zval *zm, *zxx, *zyy;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
		Z_PARAM_ZVAL(zxx) Z_PARAM_ZVAL(zyy)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	float xx, yy;
	plutovg_matrix_map(&m, (float) x, (float) y, &xx, &yy);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zxx, xx);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zyy, yy);
}

ZEND_FUNCTION(plutovg_matrix_map_point)
{
	zval *zm, *zs, *zd;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_point_ce)
		Z_PARAM_OBJECT_OF_CLASS(zd, pv_point_ce)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_point_t src, dst;
	pv_point_read(Z_OBJ_P(zs), &src);
	plutovg_matrix_map_point(&m, &src, &dst);
	pv_point_write(Z_OBJ_P(zd), &dst);
}

ZEND_FUNCTION(plutovg_matrix_map_points)
{
	zval *zm, *zdst;
	HashTable *src;
	zend_long count;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_ARRAY_HT(src)
		Z_PARAM_ZVAL(zdst)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	if (count > INT_MAX) {
		zend_argument_value_error(4, "must be at most INT_MAX");
		RETURN_THROWS();
	}
	MATRIX_IN(zm, m);
	plutovg_point_t *pts = count > 0 ? safe_emalloc(count, sizeof(plutovg_point_t), 0) : NULL;
	if (!pv_points_read(src, count, pts, 2)) {
		if (pts) efree(pts);
		RETURN_THROWS();
	}
	plutovg_matrix_map_points(&m, pts, pts, (int) count);
	zval list;
	array_init_size(&list, (uint32_t) count);
	for (zend_long i = 0; i < count; i++) {
		zval p;
		pv_point_new(&pts[i], &p);
		add_next_index_zval(&list, &p);
	}
	if (pts) efree(pts);
	ZEND_TRY_ASSIGN_REF_TMP(zdst, &list);
}

ZEND_FUNCTION(plutovg_matrix_map_rect)
{
	zval *zm, *zs, *zd;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_rect_ce)
		Z_PARAM_OBJECT_OF_CLASS(zd, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	MATRIX_IN(zm, m);
	plutovg_rect_t src, dst;
	pv_rect_read(Z_OBJ_P(zs), &src);
	plutovg_matrix_map_rect(&m, &src, &dst);
	pv_rect_write(Z_OBJ_P(zd), &dst);
}

ZEND_FUNCTION(plutovg_matrix_parse)
{
	zval *zm;
	zend_string *data;
	zend_long length;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_length(data, length, 3)) {
		RETURN_THROWS();
	}
	MATRIX_IN(zm, m);
	bool ok = plutovg_matrix_parse(&m, ZSTR_VAL(data), length == -1 ? (int) ZSTR_LEN(data) : (int) length);
	MATRIX_OUT(zm, m);
	RETURN_BOOL(ok);
}

/* ---- path iterator --------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_path_iterator_init)
{
	zval *zit, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_path_iterator_ce)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_path_t *path = pv_path_arg(zp, 2);
	if (!path) {
		RETURN_THROWS();
	}
	pv_path_iterator_obj *it = pv_path_iterator_from(Z_OBJ_P(zit));
	if (it->path) {
		OBJ_RELEASE(it->path);
	}
	it->path = Z_OBJ_P(zp);
	GC_ADDREF(it->path);
	plutovg_path_iterator_init(&it->it, path);
	it->size = plutovg_path_get_elements(path, &it->elements);
}

/* The iterator's path, still holding what it held at init; NULL with ValueError otherwise. */
static pv_path_iterator_obj *pv_live_iterator(zval *zit)
{
	pv_path_iterator_obj *it = pv_path_iterator_from(Z_OBJ_P(zit));
	if (!it->path) {
		zend_argument_value_error(1, "has not been initialised by plutovg_path_iterator_init()");
		return NULL;
	}
	plutovg_path_t *path = pv_path_from(it->path)->path;
	const plutovg_path_element_t *elements = NULL;
	if (!path || plutovg_path_get_elements(path, &elements) != it->size || elements != it->elements) {
		zend_argument_value_error(1, "iterates a path that changed or was released since plutovg_path_iterator_init()");
		return NULL;
	}
	return it;
}

ZEND_FUNCTION(plutovg_path_iterator_has_next)
{
	zval *zit;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_path_iterator_ce)
	ZEND_PARSE_PARAMETERS_END();
	pv_path_iterator_obj *it = pv_live_iterator(zit);
	if (!it) {
		RETURN_THROWS();
	}
	RETURN_BOOL(plutovg_path_iterator_has_next(&it->it));
}

ZEND_FUNCTION(plutovg_path_iterator_next)
{
	zval *zit, *zpoints;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_path_iterator_ce)
		Z_PARAM_ZVAL(zpoints)
	ZEND_PARSE_PARAMETERS_END();
	pv_path_iterator_obj *it = pv_live_iterator(zit);
	if (!it) {
		RETURN_THROWS();
	}
	/* PlutoVG reads past the elements when called at the end. */
	if (!plutovg_path_iterator_has_next(&it->it)) {
		zend_argument_value_error(1, "is at the end of the path (plutovg_path_iterator_has_next() is false)");
		RETURN_THROWS();
	}
	plutovg_point_t points[3] = {{0}};
	plutovg_path_command_t command = plutovg_path_iterator_next(&it->it, points);
	zval list;
	array_init_size(&list, 3);
	for (int i = 0; i < 3; i++) {
		zval p;
		pv_point_new(&points[i], &p);
		add_next_index_zval(&list, &p);
	}
	ZEND_TRY_ASSIGN_REF_TMP(zpoints, &list);
	RETURN_LONG(command);
}

/* ---- paths ----------------------------------------------------------------------------------- */

/* The path argument of every path function; returns from the function when released. */
#define PATH_ARG(zv, num, var) plutovg_path_t *var = pv_path_arg(zv, num); if (!var) { RETURN_THROWS(); }

ZEND_FUNCTION(plutovg_path_create)
{
	ZEND_PARSE_PARAMETERS_NONE();
	pv_path_wrap(plutovg_path_create(), return_value);
}

ZEND_FUNCTION(plutovg_path_reference)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	pv_path_wrap(plutovg_path_reference(path), return_value);
}

ZEND_FUNCTION(plutovg_path_destroy)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	pv_path_from(Z_OBJ_P(zp))->path = NULL;
	plutovg_path_destroy(path);
}

ZEND_FUNCTION(plutovg_path_get_reference_count)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	RETURN_LONG(plutovg_path_get_reference_count(path));
}

ZEND_FUNCTION(plutovg_path_get_elements)
{
	zval *zp, *zelements;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_ZVAL(zelements)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	const plutovg_path_element_t *elements = NULL;
	int size = plutovg_path_get_elements(path, &elements);
	zval list;
	array_init_size(&list, (uint32_t) size);
	/* The union is read the way PlutoVG lays it out: a header, then length - 1 points. */
	for (int i = 0; i < size;) {
		zval e, h;
		object_init_ex(&e, pv_path_element_ce);
		object_init_ex(&h, pv_path_element_header_ce);
		zend_update_property_long(pv_path_element_header_ce, Z_OBJ(h), "command", sizeof("command") - 1, elements[i].header.command);
		zend_update_property_long(pv_path_element_header_ce, Z_OBJ(h), "length", sizeof("length") - 1, elements[i].header.length);
		zend_update_property(pv_path_element_ce, Z_OBJ(e), "header", sizeof("header") - 1, &h);
		zval_ptr_dtor(&h);
		add_next_index_zval(&list, &e);
		int length = elements[i].header.length;
		for (int j = 1; j < length && i + j < size; j++) {
			zval pe, p;
			object_init_ex(&pe, pv_path_element_ce);
			pv_point_new(&elements[i + j].point, &p);
			zend_update_property(pv_path_element_ce, Z_OBJ(pe), "point", sizeof("point") - 1, &p);
			zval_ptr_dtor(&p);
			add_next_index_zval(&list, &pe);
		}
		i += length > 0 ? length : 1;
	}
	ZEND_TRY_ASSIGN_REF_TMP(zelements, &list);
	RETURN_LONG(size);
}

ZEND_FUNCTION(plutovg_path_move_to)
{
	zval *zp;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_move_to(path, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_path_line_to)
{
	zval *zp;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_line_to(path, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_path_quad_to)
{
	zval *zp;
	double x1, y1, x2, y2;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x1) Z_PARAM_DOUBLE(y1) Z_PARAM_DOUBLE(x2) Z_PARAM_DOUBLE(y2)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_quad_to(path, (float) x1, (float) y1, (float) x2, (float) y2);
}

ZEND_FUNCTION(plutovg_path_cubic_to)
{
	zval *zp;
	double x1, y1, x2, y2, x3, y3;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x1) Z_PARAM_DOUBLE(y1) Z_PARAM_DOUBLE(x2) Z_PARAM_DOUBLE(y2)
		Z_PARAM_DOUBLE(x3) Z_PARAM_DOUBLE(y3)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_cubic_to(path, (float) x1, (float) y1, (float) x2, (float) y2, (float) x3, (float) y3);
}

ZEND_FUNCTION(plutovg_path_arc_to)
{
	zval *zp;
	double rx, ry, angle, x, y;
	bool large_arc_flag, sweep_flag;
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(rx) Z_PARAM_DOUBLE(ry) Z_PARAM_DOUBLE(angle)
		Z_PARAM_BOOL(large_arc_flag) Z_PARAM_BOOL(sweep_flag)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_arc_to(path, (float) rx, (float) ry, (float) angle, large_arc_flag, sweep_flag, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_path_close)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_close(path);
}

ZEND_FUNCTION(plutovg_path_get_current_point)
{
	zval *zp, *zx, *zy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_ZVAL(zx) Z_PARAM_ZVAL(zy)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	float x, y;
	plutovg_path_get_current_point(path, &x, &y);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zx, x);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zy, y);
}

/* plutovg_array_ensure adds to an int size and doubles an int capacity, and does not check realloc. */
#define PV_MAX_ELEMENTS (1 << 24)

ZEND_FUNCTION(plutovg_path_reserve)
{
	zval *zp;
	zend_long count;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	const plutovg_path_element_t *elements;
	int size = plutovg_path_get_elements(path, &elements);
	if (count < 0 || count > PV_MAX_ELEMENTS - size) {
		zend_argument_value_error(2, "must be between 0 and %d (the elements a path may reserve, less the %d it holds)", PV_MAX_ELEMENTS - size, size);
		RETURN_THROWS();
	}
	plutovg_path_reserve(path, (int) count);
}

ZEND_FUNCTION(plutovg_path_reset)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_reset(path);
}

ZEND_FUNCTION(plutovg_path_add_rect)
{
	zval *zp;
	double x, y, w, h;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y) Z_PARAM_DOUBLE(w) Z_PARAM_DOUBLE(h)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_add_rect(path, (float) x, (float) y, (float) w, (float) h);
}

ZEND_FUNCTION(plutovg_path_add_round_rect)
{
	zval *zp;
	double x, y, w, h, rx, ry;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y) Z_PARAM_DOUBLE(w) Z_PARAM_DOUBLE(h)
		Z_PARAM_DOUBLE(rx) Z_PARAM_DOUBLE(ry)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_add_round_rect(path, (float) x, (float) y, (float) w, (float) h, (float) rx, (float) ry);
}

ZEND_FUNCTION(plutovg_path_add_ellipse)
{
	zval *zp;
	double cx, cy, rx, ry;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(rx) Z_PARAM_DOUBLE(ry)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_add_ellipse(path, (float) cx, (float) cy, (float) rx, (float) ry);
}

ZEND_FUNCTION(plutovg_path_add_circle)
{
	zval *zp;
	double cx, cy, r;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(r)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_add_circle(path, (float) cx, (float) cy, (float) r);
}

ZEND_FUNCTION(plutovg_path_add_arc)
{
	zval *zp;
	double cx, cy, r, a0, a1;
	bool ccw;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(a0) Z_PARAM_DOUBLE(a1)
		Z_PARAM_BOOL(ccw)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	/* A NaN sweep makes PlutoVG cast NaN to its segment count (undefined behaviour). */
	if (!isfinite((float) a0) || !isfinite((float) a1)) {
		zend_argument_value_error(isfinite((float) a0) ? 6 : 5, "must be a finite angle");
		RETURN_THROWS();
	}
	plutovg_path_add_arc(path, (float) cx, (float) cy, (float) r, (float) a0, (float) a1, ccw);
}

ZEND_FUNCTION(plutovg_path_add_path)
{
	zval *zp, *zs, *zm;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_path_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	PATH_ARG(zs, 2, source);
	/* PlutoVG grows the destination array, then copies from the source's old one: same path, freed memory. */
	if (path == source) {
		zend_argument_value_error(2, "must not be the same path as argument #1 ($path); add a plutovg_path_clone() of it");
		RETURN_THROWS();
	}
	if (zm) {
		MATRIX_IN(zm, m);
		plutovg_path_add_path(path, source, &m);
	} else {
		plutovg_path_add_path(path, source, NULL);
	}
}

ZEND_FUNCTION(plutovg_path_transform)
{
	zval *zp, *zm;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	MATRIX_IN(zm, m);
	plutovg_path_transform(path, &m);
}

/* ---- traversal ------------------------------------------------------------------------------- */

typedef struct {
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
} pv_traverse_closure;

/* PlutoVG calls this on the calling PHP thread. After a callable throws, the rest of the walk is skipped. */
static void pv_traverse(void *closure, plutovg_path_command_t command, const plutovg_point_t *points, int npoints)
{
	pv_traverse_closure *c = closure;
	if (EG(exception)) {
		return;
	}
	zval args[3], retval;
	ZVAL_LONG(&args[0], command);
	array_init_size(&args[1], (uint32_t) npoints);
	for (int i = 0; i < npoints; i++) {
		zval p;
		pv_point_new(&points[i], &p);
		add_next_index_zval(&args[1], &p);
	}
	ZVAL_LONG(&args[2], npoints);
	ZVAL_UNDEF(&retval);
	c->fci.retval = &retval;
	c->fci.params = args;
	c->fci.param_count = 3;
	zend_call_function(&c->fci, &c->fcc);
	zval_ptr_dtor(&retval);
	zval_ptr_dtor(&args[1]);
}

ZEND_FUNCTION(plutovg_path_traverse)
{
	zval *zp;
	pv_traverse_closure c;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_FUNC(c.fci, c.fcc)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	/* The callable may release or change the path; PlutoVG walks it as it stood, so it walks a reference. */
	plutovg_path_t *held = plutovg_path_clone(path);
	plutovg_path_traverse(held, pv_traverse, &c);
	plutovg_path_destroy(held);
}

ZEND_FUNCTION(plutovg_path_traverse_flatten)
{
	zval *zp;
	pv_traverse_closure c;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_FUNC(c.fci, c.fcc)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_path_t *held = plutovg_path_clone(path);
	plutovg_path_traverse_flatten(held, pv_traverse, &c);
	plutovg_path_destroy(held);
}

ZEND_FUNCTION(plutovg_path_traverse_dashed)
{
	zval *zp;
	double offset;
	HashTable *zdashes;
	zend_long ndashes;
	pv_traverse_closure c;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(offset)
		Z_PARAM_ARRAY_HT(zdashes)
		Z_PARAM_LONG(ndashes)
		Z_PARAM_FUNC(c.fci, c.fcc)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	float *dashes;
	if (!pv_dashes(zdashes, ndashes, path, &dashes, 4)) {
		RETURN_THROWS();
	}
	plutovg_path_t *held = plutovg_path_clone(path);
	plutovg_path_traverse_dashed(held, (float) offset, dashes, (int) ndashes, pv_traverse, &c);
	plutovg_path_destroy(held);
	if (dashes) efree(dashes);
}

ZEND_FUNCTION(plutovg_path_clone)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	pv_path_wrap(plutovg_path_clone(path), return_value);
}

ZEND_FUNCTION(plutovg_path_clone_flatten)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	pv_path_wrap(plutovg_path_clone_flatten(path), return_value);
}

ZEND_FUNCTION(plutovg_path_clone_dashed)
{
	zval *zp;
	double offset;
	HashTable *zdashes;
	zend_long ndashes;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_DOUBLE(offset)
		Z_PARAM_ARRAY_HT(zdashes)
		Z_PARAM_LONG(ndashes)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	float *dashes;
	if (!pv_dashes(zdashes, ndashes, path, &dashes, 4)) {
		RETURN_THROWS();
	}
	pv_path_wrap(plutovg_path_clone_dashed(path, (float) offset, dashes, (int) ndashes), return_value);
	if (dashes) efree(dashes);
}

ZEND_FUNCTION(plutovg_path_extents)
{
	zval *zp, *zr;
	bool tight;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
		Z_PARAM_BOOL(tight)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	plutovg_rect_t extents;
	float length = plutovg_path_extents(path, zr ? &extents : NULL, tight);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
	RETURN_DOUBLE(length);
}

ZEND_FUNCTION(plutovg_path_length)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	RETURN_DOUBLE(plutovg_path_length(path));
}

ZEND_FUNCTION(plutovg_path_parse)
{
	zval *zp;
	zend_string *data;
	zend_long length;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	PATH_ARG(zp, 1, path);
	if (!pv_length(data, length, 3)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(plutovg_path_parse(path, ZSTR_VAL(data), length == -1 ? (int) ZSTR_LEN(data) : (int) length));
}

/* ---- text iterator --------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_text_iterator_init)
{
	zval *zit;
	zend_string *text;
	zend_long length, encoding;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_text_iterator_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
	ZEND_PARSE_PARAMETERS_END();
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	pv_text_iterator_obj *it = pv_text_iterator_from(Z_OBJ_P(zit));
	if (it->text) {
		zend_string_release(it->text);
	}
	it->text = zend_string_copy(text);
	plutovg_text_iterator_init(&it->it, ZSTR_VAL(it->text), units, (plutovg_text_encoding_t) encoding);
}

static pv_text_iterator_obj *pv_live_text_iterator(zval *zit)
{
	pv_text_iterator_obj *it = pv_text_iterator_from(Z_OBJ_P(zit));
	if (!it->text) {
		zend_argument_value_error(1, "has not been initialised by plutovg_text_iterator_init()");
		return NULL;
	}
	return it;
}

ZEND_FUNCTION(plutovg_text_iterator_has_next)
{
	zval *zit;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_text_iterator_ce)
	ZEND_PARSE_PARAMETERS_END();
	pv_text_iterator_obj *it = pv_live_text_iterator(zit);
	if (!it) {
		RETURN_THROWS();
	}
	RETURN_BOOL(plutovg_text_iterator_has_next(&it->it));
}

ZEND_FUNCTION(plutovg_text_iterator_next)
{
	zval *zit;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zit, pv_text_iterator_ce)
	ZEND_PARSE_PARAMETERS_END();
	pv_text_iterator_obj *it = pv_live_text_iterator(zit);
	if (!it) {
		RETURN_THROWS();
	}
	/* PlutoVG reads the unit at index without checking it is inside the text. */
	if (!plutovg_text_iterator_has_next(&it->it)) {
		zend_argument_value_error(1, "is at the end of its text (plutovg_text_iterator_has_next() is false)");
		RETURN_THROWS();
	}
	RETURN_LONG(plutovg_text_iterator_next(&it->it));
}
