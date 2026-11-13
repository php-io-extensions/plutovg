/*
 * Font faces and font face caches: plutovg.h from plutovg_font_face_load_from_file to
 * plutovg_font_face_cache_load_sys. Every function written out.
 *
 * Font data goes to stb_truetype, which trusts it (offsets and table sizes are not checked
 * against the data's length). The binding checks what it can; it cannot make a hostile font safe.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "main/fopen_wrappers.h"
#include "runtime.h"
#include "../stubs/plutovg_font_arginfo.h"

void pv_font_minit(void) { zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT); }

#define FACE_ARG(zv, num, var) plutovg_font_face_t *var = pv_handle_arg(zv, num); if (!var) { RETURN_THROWS(); }
#define CACHE_ARG(zv, num, var) plutovg_font_face_cache_t *var = pv_handle_arg(zv, num); if (!var) { RETURN_THROWS(); }

/* Smallest data stb_truetype reads before it can tell it is not a font: the offset table. */
#define PV_MIN_FONT 12

static bool pv_ttcindex(zend_long ttcindex, uint32_t arg_num)
{
	if (ttcindex < 0 || ttcindex > INT_MAX) {
		zend_argument_value_error(arg_num, "must be between 0 and INT_MAX");
		return false;
	}
	return true;
}

/* The font face's copy of its data, freed by PlutoVG when the face goes. */
static void pv_font_data_free(void *closure)
{
	free(closure);
}

ZEND_FUNCTION(plutovg_font_face_load_from_file)
{
	char *filename;
	size_t filename_len;
	zend_long ttcindex;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_PATH(filename, filename_len)
		Z_PARAM_LONG(ttcindex)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_ttcindex(ttcindex, 2)) {
		RETURN_THROWS();
	}
	if (php_check_open_basedir(filename)) {
		RETURN_NULL();
	}
	pv_handle_wrap(pv_font_face_ce, plutovg_font_face_load_from_file(filename, (int) ttcindex), NULL, return_value);
}

ZEND_FUNCTION(plutovg_font_face_load_from_data)
{
	zend_string *data;
	zend_long length, ttcindex;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(ttcindex)
	ZEND_PARSE_PARAMETERS_END();
	if (length < PV_MIN_FONT || length > (zend_long) ZSTR_LEN(data) || length > UINT_MAX) {
		zend_argument_value_error(2, "must be between %d and the string's length (%zu)", PV_MIN_FONT, ZSTR_LEN(data));
		RETURN_THROWS();
	}
	if (!pv_ttcindex(ttcindex, 3)) {
		RETURN_THROWS();
	}
	void *copy = malloc((size_t) length);
	if (!copy) {
		zend_throw_error(NULL, "out of memory copying font data");
		RETURN_THROWS();
	}
	memcpy(copy, ZSTR_VAL(data), (size_t) length);
	/* PlutoVG calls the destroy function itself when the data is not a font. */
	pv_handle_wrap(pv_font_face_ce, plutovg_font_face_load_from_data(copy, (unsigned int) length, (int) ttcindex, pv_font_data_free, copy),
		NULL, return_value);
}

ZEND_FUNCTION(plutovg_font_face_reference)
{
	zval *zf;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	pv_handle_wrap(pv_font_face_ce, plutovg_font_face_reference(face), Z_OBJ_P(zf), return_value);
}

ZEND_FUNCTION(plutovg_font_face_destroy)
{
	zval *zf;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	(void) face;
	pv_handle_release(Z_OBJ_P(zf));
}

ZEND_FUNCTION(plutovg_font_face_get_reference_count)
{
	zval *zf;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	RETURN_LONG(plutovg_font_face_get_reference_count(face));
}

ZEND_FUNCTION(plutovg_font_face_get_metrics)
{
	zval *zf, *zascent, *zdescent, *zgap, *zr;
	double size;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size)
		Z_PARAM_ZVAL(zascent) Z_PARAM_ZVAL(zdescent) Z_PARAM_ZVAL(zgap)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	float ascent, descent, line_gap;
	plutovg_rect_t extents;
	plutovg_font_face_get_metrics(face, (float) size, &ascent, &descent, &line_gap, zr ? &extents : NULL);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zascent, ascent);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zdescent, descent);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zgap, line_gap);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
}

ZEND_FUNCTION(plutovg_font_face_get_glyph_metrics)
{
	zval *zf, *zadvance, *zbearing, *zr;
	double size;
	zend_long codepoint;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size)
		Z_PARAM_LONG(codepoint)
		Z_PARAM_ZVAL(zadvance) Z_PARAM_ZVAL(zbearing)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	if (!pv_codepoint(codepoint, 3)) {
		RETURN_THROWS();
	}
	float advance_width, left_side_bearing;
	plutovg_rect_t extents;
	plutovg_font_face_get_glyph_metrics(face, (float) size, (plutovg_codepoint_t) codepoint, &advance_width, &left_side_bearing, zr ? &extents : NULL);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zadvance, advance_width);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zbearing, left_side_bearing);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
}

ZEND_FUNCTION(plutovg_font_face_get_glyph_path)
{
	zval *zf, *zp;
	double size, x, y;
	zend_long codepoint;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size) Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
		Z_PARAM_LONG(codepoint)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	if (!pv_codepoint(codepoint, 5)) {
		RETURN_THROWS();
	}
	plutovg_path_t *path = pv_path_arg(zp, 6);
	if (!path) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(plutovg_font_face_get_glyph_path(face, (float) size, (float) x, (float) y, (plutovg_codepoint_t) codepoint, path));
}

typedef struct {
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
} pv_glyph_closure;

static void pv_glyph_traverse(void *closure, plutovg_path_command_t command, const plutovg_point_t *points, int npoints)
{
	pv_glyph_closure *c = closure;
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

ZEND_FUNCTION(plutovg_font_face_traverse_glyph_path)
{
	zval *zf;
	double size, x, y;
	zend_long codepoint;
	pv_glyph_closure c;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size) Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
		Z_PARAM_LONG(codepoint)
		Z_PARAM_FUNC(c.fci, c.fcc)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	if (!pv_codepoint(codepoint, 5)) {
		RETURN_THROWS();
	}
	/* The callable may destroy the face's last PHP handle; the walk holds its own reference. */
	plutovg_font_face_t *held = plutovg_font_face_reference(face);
	float advance = plutovg_font_face_traverse_glyph_path(held, (float) size, (float) x, (float) y, (plutovg_codepoint_t) codepoint, pv_glyph_traverse, &c);
	plutovg_font_face_destroy(held);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(advance);
}

ZEND_FUNCTION(plutovg_font_face_text_extents)
{
	zval *zf, *zr;
	double size;
	zend_string *text;
	zend_long length, encoding;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	FACE_ARG(zf, 1, face);
	int units;
	if (!pv_text(text, length, encoding, &units, 4)) {
		RETURN_THROWS();
	}
	plutovg_rect_t extents;
	float advance = plutovg_font_face_text_extents(face, (float) size, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, zr ? &extents : NULL);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
	RETURN_DOUBLE(advance);
}

/* ---- caches ---------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_font_face_cache_create)
{
	ZEND_PARSE_PARAMETERS_NONE();
	pv_handle_wrap(pv_font_face_cache_ce, plutovg_font_face_cache_create(), NULL, return_value);
}

ZEND_FUNCTION(plutovg_font_face_cache_reference)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	pv_handle_wrap(pv_font_face_cache_ce, plutovg_font_face_cache_reference(cache), Z_OBJ_P(zc), return_value);
}

ZEND_FUNCTION(plutovg_font_face_cache_destroy)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	(void) cache;
	pv_handle_release(Z_OBJ_P(zc));
}

ZEND_FUNCTION(plutovg_font_face_cache_reference_count)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	RETURN_LONG(plutovg_font_face_cache_reference_count(cache));
}

ZEND_FUNCTION(plutovg_font_face_cache_reset)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	plutovg_font_face_cache_reset(cache);
}

ZEND_FUNCTION(plutovg_font_face_cache_add)
{
	zval *zc, *zf;
	char *family;
	size_t family_len;
	bool bold, italic;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	plutovg_font_face_t *face = NULL;
	if (zf && !(face = pv_handle_arg(zf, 5))) {
		RETURN_THROWS();
	}
	plutovg_font_face_cache_add(cache, family, bold, italic, face);
}

ZEND_FUNCTION(plutovg_font_face_cache_add_file)
{
	zval *zc;
	char *family, *filename;
	size_t family_len, filename_len;
	bool bold, italic;
	zend_long ttcindex;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
		Z_PARAM_PATH(filename, filename_len)
		Z_PARAM_LONG(ttcindex)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	if (!pv_ttcindex(ttcindex, 6)) {
		RETURN_THROWS();
	}
	if (php_check_open_basedir(filename)) {
		RETURN_FALSE;
	}
	RETURN_BOOL(plutovg_font_face_cache_add_file(cache, family, bold, italic, filename, (int) ttcindex));
}

ZEND_FUNCTION(plutovg_font_face_cache_get)
{
	zval *zc;
	char *family;
	size_t family_len;
	bool bold, italic;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	/* The cache keeps the face; the returned handle takes a reference of its own. */
	plutovg_font_face_t *face = plutovg_font_face_cache_get(cache, family, bold, italic);
	pv_handle_wrap(pv_font_face_ce, face ? plutovg_font_face_reference(face) : NULL, NULL, return_value);
}

ZEND_FUNCTION(plutovg_font_face_cache_load_file)
{
	zval *zc;
	char *filename;
	size_t filename_len;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
		Z_PARAM_PATH(filename, filename_len)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	if (php_check_open_basedir(filename)) {
		RETURN_LONG(0);
	}
	RETURN_LONG(plutovg_font_face_cache_load_file(cache, filename));
}

ZEND_FUNCTION(plutovg_font_face_cache_load_dir)
{
	zval *zc;
	char *dirname;
	size_t dirname_len;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
		Z_PARAM_PATH(dirname, dirname_len)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	if (php_check_open_basedir(dirname)) {
		RETURN_LONG(0);
	}
	RETURN_LONG(plutovg_font_face_cache_load_dir(cache, dirname));
}

ZEND_FUNCTION(plutovg_font_face_cache_load_sys)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CACHE_ARG(zc, 1, cache);
	if (PG(open_basedir) && *PG(open_basedir)) {
		php_error_docref(NULL, E_WARNING, "open_basedir restriction in effect: the system font directories are not scanned");
		RETURN_LONG(0);
	}
	RETURN_LONG(plutovg_font_face_cache_load_sys(cache));
}
