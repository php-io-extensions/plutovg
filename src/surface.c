/*
 * Colours, surfaces (images in and out) and paints: plutovg.h from plutovg_color_init_rgb to
 * plutovg_paint_get_reference_count. Every function written out.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "main/php_open_temporary_file.h"
#include "main/fopen_wrappers.h"
#include "runtime.h"
#include "../stubs/plutovg_surface_arginfo.h"

void pv_surface_minit(void) { zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT); }

#define COLOR_ARG(zv, c) plutovg_color_t c; pv_color_read(Z_OBJ_P(zv), &c)
#define SURFACE_ARG(zv, num, var) plutovg_surface_t *var = pv_handle_arg(zv, num); if (!var) { RETURN_THROWS(); }
#define PAINT_ARG(zv, num, var) plutovg_paint_t *var = pv_handle_arg(zv, num); if (!var) { RETURN_THROWS(); }

/* PlutoVG's own surface limit (plutovg_surface_create refuses 1 << 15 and up). */
#define PV_MAX_SIDE ((1 << 15) - 1)

/* ---- colours --------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_color_init_rgb)
{
	zval *zc;
	double r, g, b;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_DOUBLE(r) Z_PARAM_DOUBLE(g) Z_PARAM_DOUBLE(b)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_color_t c;
	plutovg_color_init_rgb(&c, (float) r, (float) g, (float) b);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_init_rgba)
{
	zval *zc;
	double r, g, b, a;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_DOUBLE(r) Z_PARAM_DOUBLE(g) Z_PARAM_DOUBLE(b) Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_color_t c;
	plutovg_color_init_rgba(&c, (float) r, (float) g, (float) b, (float) a);
	pv_color_write(Z_OBJ_P(zc), &c);
}

/* An int argument C passes on as int. */
static bool pv_int(zend_long v, uint32_t arg_num)
{
	if (v < INT_MIN || v > INT_MAX) {
		zend_argument_value_error(arg_num, "must be a C int");
		return false;
	}
	return true;
}

ZEND_FUNCTION(plutovg_color_init_rgb8)
{
	zval *zc;
	zend_long r, g, b;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_LONG(r) Z_PARAM_LONG(g) Z_PARAM_LONG(b)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_int(r, 2) || !pv_int(g, 3) || !pv_int(b, 4)) {
		RETURN_THROWS();
	}
	plutovg_color_t c;
	plutovg_color_init_rgb8(&c, (int) r, (int) g, (int) b);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_init_rgba8)
{
	zval *zc;
	zend_long r, g, b, a;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_LONG(r) Z_PARAM_LONG(g) Z_PARAM_LONG(b) Z_PARAM_LONG(a)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_int(r, 2) || !pv_int(g, 3) || !pv_int(b, 4) || !pv_int(a, 5)) {
		RETURN_THROWS();
	}
	plutovg_color_t c;
	plutovg_color_init_rgba8(&c, (int) r, (int) g, (int) b, (int) a);
	pv_color_write(Z_OBJ_P(zc), &c);
}

static bool pv_u32(zend_long v, uint32_t arg_num)
{
	if (v < 0 || v > 0xFFFFFFFF) {
		zend_argument_value_error(arg_num, "must be between 0 and 0xFFFFFFFF");
		return false;
	}
	return true;
}

ZEND_FUNCTION(plutovg_color_init_rgba32)
{
	zval *zc;
	zend_long value;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_u32(value, 2)) {
		RETURN_THROWS();
	}
	plutovg_color_t c;
	plutovg_color_init_rgba32(&c, (unsigned int) value);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_init_argb32)
{
	zval *zc;
	zend_long value;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_u32(value, 2)) {
		RETURN_THROWS();
	}
	plutovg_color_t c;
	plutovg_color_init_argb32(&c, (unsigned int) value);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_init_hsl)
{
	zval *zc;
	double h, s, l;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_DOUBLE(h) Z_PARAM_DOUBLE(s) Z_PARAM_DOUBLE(l)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_color_t c;
	plutovg_color_init_hsl(&c, (float) h, (float) s, (float) l);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_init_hsla)
{
	zval *zc;
	double h, s, l, a;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_DOUBLE(h) Z_PARAM_DOUBLE(s) Z_PARAM_DOUBLE(l) Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_color_t c;
	plutovg_color_init_hsla(&c, (float) h, (float) s, (float) l, (float) a);
	pv_color_write(Z_OBJ_P(zc), &c);
}

ZEND_FUNCTION(plutovg_color_to_rgba32)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	COLOR_ARG(zc, c);
	RETURN_LONG((zend_long) plutovg_color_to_rgba32(&c));
}

ZEND_FUNCTION(plutovg_color_to_argb32)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	COLOR_ARG(zc, c);
	RETURN_LONG((zend_long) plutovg_color_to_argb32(&c));
}

ZEND_FUNCTION(plutovg_color_parse)
{
	zval *zc;
	zend_string *data;
	zend_long length;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_length(data, length, 3)) {
		RETURN_THROWS();
	}
	COLOR_ARG(zc, c);
	int consumed = plutovg_color_parse(&c, ZSTR_VAL(data), length == -1 ? (int) ZSTR_LEN(data) : (int) length);
	pv_color_write(Z_OBJ_P(zc), &c);
	RETURN_LONG(consumed);
}

/* ---- surfaces -------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_surface_create)
{
	zend_long width, height;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width) Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_int(width, 1) || !pv_int(height, 2)) {
		RETURN_THROWS();
	}
	pv_handle_wrap(pv_surface_ce, plutovg_surface_create((int) width, (int) height), NULL, return_value);
}

/* A borrowed-memory surface's geometry: what PlutoVG's own create checks, plus a stride that holds a row. */
static bool pv_geometry(zend_long width, zend_long height, zend_long stride, uint32_t first)
{
	if (width < 1 || width > PV_MAX_SIDE) {
		zend_argument_value_error(first, "must be between 1 and %d", PV_MAX_SIDE);
		return false;
	}
	if (height < 1 || height > PV_MAX_SIDE) {
		zend_argument_value_error(first + 1, "must be between 1 and %d", PV_MAX_SIDE);
		return false;
	}
	if (stride < width * 4 || stride > INT_MAX / height || stride % 4 != 0) {
		zend_argument_value_error(first + 2, "must be a multiple of 4 of at least width * 4 (" ZEND_LONG_FMT ")", width * 4);
		return false;
	}
	return true;
}

ZEND_FUNCTION(plutovg_surface_create_for_data)
{
	zend_string *data;
	zend_long width, height, stride;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(width) Z_PARAM_LONG(height) Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_geometry(width, height, stride, 2)) {
		RETURN_THROWS();
	}
	if ((zend_long) ZSTR_LEN(data) < stride * height) {
		zend_argument_value_error(1, "must hold stride * height bytes (" ZEND_LONG_FMT ", %zu given)", stride * height, ZSTR_LEN(data));
		RETURN_THROWS();
	}
	/* The surface writes into its pixels, so it gets a string of its own (never an interned or shared one). */
	zval held;
	ZVAL_STR(&held, zend_string_init(ZSTR_VAL(data), ZSTR_LEN(data), 0));
	plutovg_surface_t *surface = plutovg_surface_create_for_data((unsigned char *) Z_STRVAL(held), (int) width, (int) height, (int) stride);
	pv_handle_wrap(pv_surface_ce, surface, NULL, return_value);
	if (surface) {
		pv_handle_keep(Z_OBJ_P(return_value), NULL, &held);
	}
	zval_ptr_dtor(&held);
}

ZEND_FUNCTION(plutovg_surface_create_for_address)
{
	zend_long address, width, height, stride;
	zval *owner;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(address)
		Z_PARAM_LONG(width) Z_PARAM_LONG(height) Z_PARAM_LONG(stride)
		Z_PARAM_OBJECT(owner)
	ZEND_PARSE_PARAMETERS_END();
	if (address == 0 || address % 4 != 0) {
		zend_argument_value_error(1, "must be a non-zero, 4-byte aligned address");
		RETURN_THROWS();
	}
	if (!pv_geometry(width, height, stride, 2)) {
		RETURN_THROWS();
	}
	plutovg_surface_t *surface = plutovg_surface_create_for_data((unsigned char *) (uintptr_t) address, (int) width, (int) height, (int) stride);
	pv_handle_wrap(pv_surface_ce, surface, NULL, return_value);
	if (surface) {
		pv_handle_keep(Z_OBJ_P(return_value), NULL, owner);
	}
}

/* A filename argument PlutoVG opens itself: open_basedir applies as it would to fopen(). */
static bool pv_file(const char *filename)
{
	return php_check_open_basedir(filename) == 0;
}

ZEND_FUNCTION(plutovg_surface_load_from_image_file)
{
	char *filename;
	size_t filename_len;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_PATH(filename, filename_len)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_file(filename)) {
		RETURN_NULL();
	}
	pv_handle_wrap(pv_surface_ce, plutovg_surface_load_from_image_file(filename), NULL, return_value);
}

ZEND_FUNCTION(plutovg_surface_load_from_image_data)
{
	zend_string *data;
	zend_long length;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_length(data, length, 2)) {
		RETURN_THROWS();
	}
	pv_handle_wrap(pv_surface_ce, plutovg_surface_load_from_image_data(ZSTR_VAL(data), length == -1 ? (int) ZSTR_LEN(data) : (int) length), NULL, return_value);
}

ZEND_FUNCTION(plutovg_surface_load_from_image_base64)
{
	zend_string *data;
	zend_long length;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_length(data, length, 2)) {
		RETURN_THROWS();
	}
	pv_handle_wrap(pv_surface_ce, plutovg_surface_load_from_image_base64(ZSTR_VAL(data), length == -1 ? (int) ZSTR_LEN(data) : (int) length), NULL, return_value);
}

ZEND_FUNCTION(plutovg_surface_reference)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	pv_handle_wrap(pv_surface_ce, plutovg_surface_reference(surface), Z_OBJ_P(zs), return_value);
}

ZEND_FUNCTION(plutovg_surface_destroy)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	(void) surface;
	pv_handle_release(Z_OBJ_P(zs));
}

ZEND_FUNCTION(plutovg_surface_get_reference_count)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_LONG(plutovg_surface_get_reference_count(surface));
}

ZEND_FUNCTION(plutovg_surface_get_data)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	size_t size = (size_t) plutovg_surface_get_stride(surface) * (size_t) plutovg_surface_get_height(surface);
	RETURN_STRINGL((const char *) plutovg_surface_get_data(surface), size);
}

ZEND_FUNCTION(plutovg_surface_get_data_address)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_LONG((zend_long) (uintptr_t) plutovg_surface_get_data(surface));
}

ZEND_FUNCTION(plutovg_surface_get_alpha)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	int width = plutovg_surface_get_width(surface), height = plutovg_surface_get_height(surface), stride = plutovg_surface_get_stride(surface);
	const unsigned char *data = plutovg_surface_get_data(surface);
	zend_string *alpha = zend_string_safe_alloc((size_t) width, (size_t) height, 0, 0);
	unsigned char *out = (unsigned char *) ZSTR_VAL(alpha);
	/* Pixels are native-endian ARGB32 words: alpha is the top byte whatever the byte order. */
	for (int y = 0; y < height; y++) {
		const uint32_t *row = (const uint32_t *) (data + (size_t) y * (size_t) stride);
		for (int x = 0; x < width; x++) {
			*out++ = (unsigned char) (row[x] >> 24);
		}
	}
	ZSTR_VAL(alpha)[ZSTR_LEN(alpha)] = '\0';
	RETURN_NEW_STR(alpha);
}

ZEND_FUNCTION(plutovg_surface_get_width)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_LONG(plutovg_surface_get_width(surface));
}

ZEND_FUNCTION(plutovg_surface_get_height)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_LONG(plutovg_surface_get_height(surface));
}

ZEND_FUNCTION(plutovg_surface_get_stride)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_LONG(plutovg_surface_get_stride(surface));
}

ZEND_FUNCTION(plutovg_surface_clear)
{
	zval *zs, *zc;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	COLOR_ARG(zc, c);
	plutovg_surface_clear(surface, &c);
}

ZEND_FUNCTION(plutovg_surface_write_to_png)
{
	zval *zs;
	char *filename;
	size_t filename_len;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_PATH(filename, filename_len)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	if (!pv_file(filename)) {
		RETURN_FALSE;
	}
	RETURN_BOOL(plutovg_surface_write_to_png(surface, filename));
}

/* stb's JPEG writer clamps quality itself; 0 and below mean its default. */
ZEND_FUNCTION(plutovg_surface_write_to_jpg)
{
	zval *zs;
	char *filename;
	size_t filename_len;
	zend_long quality;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_PATH(filename, filename_len)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	if (!pv_int(quality, 3)) {
		RETURN_THROWS();
	}
	if (!pv_file(filename)) {
		RETURN_FALSE;
	}
	RETURN_BOOL(plutovg_surface_write_to_jpg(surface, filename, (int) quality));
}

typedef struct {
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
} pv_write_closure;

/* stb's writer calls this on the calling PHP thread. After the callable throws, later chunks are dropped. */
static void pv_write(void *closure, void *data, int size)
{
	pv_write_closure *c = closure;
	if (EG(exception)) {
		return;
	}
	zval args[2], retval;
	ZVAL_STRINGL(&args[0], (const char *) data, (size_t) size);
	ZVAL_LONG(&args[1], size);
	ZVAL_UNDEF(&retval);
	c->fci.retval = &retval;
	c->fci.params = args;
	c->fci.param_count = 2;
	zend_call_function(&c->fci, &c->fcc);
	zval_ptr_dtor(&retval);
	zval_ptr_dtor(&args[0]);
}

ZEND_FUNCTION(plutovg_surface_write_to_png_stream)
{
	zval *zs;
	pv_write_closure c;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_FUNC(c.fci, c.fcc)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	RETURN_BOOL(plutovg_surface_write_to_png_stream(surface, pv_write, &c));
}

ZEND_FUNCTION(plutovg_surface_write_to_jpg_stream)
{
	zval *zs;
	pv_write_closure c;
	zend_long quality;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_FUNC(c.fci, c.fcc)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	if (!pv_int(quality, 3)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(plutovg_surface_write_to_jpg_stream(surface, pv_write, &c, (int) quality));
}

/* The conversions read and write stride * height bytes; $dst gets a string that size. */
static bool pv_convert_args(zend_string *src, zend_long width, zend_long height, zend_long stride)
{
	if (width < 0 || height < 0 || width > PV_MAX_SIDE || height > PV_MAX_SIDE) {
		zend_argument_value_error(width < 0 || width > PV_MAX_SIDE ? 3 : 4, "must be between 0 and %d", PV_MAX_SIDE);
		return false;
	}
	if (stride < width * 4 || (height > 0 && stride > INT_MAX / height)) {
		zend_argument_value_error(5, "must be at least width * 4 (" ZEND_LONG_FMT ")", width * 4);
		return false;
	}
	if ((zend_long) ZSTR_LEN(src) < stride * height) {
		zend_argument_value_error(2, "must hold stride * height bytes (" ZEND_LONG_FMT ", %zu given)", stride * height, ZSTR_LEN(src));
		return false;
	}
	return true;
}

ZEND_FUNCTION(plutovg_convert_argb_to_rgba)
{
	zval *zdst;
	zend_string *src;
	zend_long width, height, stride;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(zdst)
		Z_PARAM_STR(src)
		Z_PARAM_LONG(width) Z_PARAM_LONG(height) Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_convert_args(src, width, height, stride)) {
		RETURN_THROWS();
	}
	zend_string *dst = zend_string_alloc(ZSTR_LEN(src), 0);
	memcpy(ZSTR_VAL(dst), ZSTR_VAL(src), ZSTR_LEN(src));
	ZSTR_VAL(dst)[ZSTR_LEN(dst)] = '\0';
	plutovg_convert_argb_to_rgba((unsigned char *) ZSTR_VAL(dst), (const unsigned char *) ZSTR_VAL(src), (int) width, (int) height, (int) stride);
	ZEND_TRY_ASSIGN_REF_STR(zdst, dst);
}

ZEND_FUNCTION(plutovg_convert_rgba_to_argb)
{
	zval *zdst;
	zend_string *src;
	zend_long width, height, stride;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(zdst)
		Z_PARAM_STR(src)
		Z_PARAM_LONG(width) Z_PARAM_LONG(height) Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	if (!pv_convert_args(src, width, height, stride)) {
		RETURN_THROWS();
	}
	zend_string *dst = zend_string_alloc(ZSTR_LEN(src), 0);
	memcpy(ZSTR_VAL(dst), ZSTR_VAL(src), ZSTR_LEN(src));
	ZSTR_VAL(dst)[ZSTR_LEN(dst)] = '\0';
	plutovg_convert_rgba_to_argb((unsigned char *) ZSTR_VAL(dst), (const unsigned char *) ZSTR_VAL(src), (int) width, (int) height, (int) stride);
	ZEND_TRY_ASSIGN_REF_STR(zdst, dst);
}

/* ---- paints ---------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_paint_create_rgb)
{
	double r, g, b;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(r) Z_PARAM_DOUBLE(g) Z_PARAM_DOUBLE(b)
	ZEND_PARSE_PARAMETERS_END();
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_rgb((float) r, (float) g, (float) b), NULL, return_value);
}

ZEND_FUNCTION(plutovg_paint_create_rgba)
{
	double r, g, b, a;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_DOUBLE(r) Z_PARAM_DOUBLE(g) Z_PARAM_DOUBLE(b) Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_rgba((float) r, (float) g, (float) b, (float) a), NULL, return_value);
}

ZEND_FUNCTION(plutovg_paint_create_color)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	COLOR_ARG(zc, c);
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_color(&c), NULL, return_value);
}

ZEND_FUNCTION(plutovg_paint_create_linear_gradient)
{
	double x1, y1, x2, y2;
	zend_long spread, nstops;
	HashTable *zstops;
	zval *zm;
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_DOUBLE(x1) Z_PARAM_DOUBLE(y1) Z_PARAM_DOUBLE(x2) Z_PARAM_DOUBLE(y2)
		Z_PARAM_LONG(spread)
		Z_PARAM_ARRAY_HT(zstops)
		Z_PARAM_LONG(nstops)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_gradient_stop_t *stops;
	if (!pv_enum(spread, PLUTOVG_SPREAD_METHOD_REPEAT, "PLUTOVG_SPREAD_METHOD_", 5) || !pv_stops(zstops, nstops, &stops, 7)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_linear_gradient((float) x1, (float) y1, (float) x2, (float) y2,
		(plutovg_spread_method_t) spread, stops, (int) nstops, zm ? &m : NULL), NULL, return_value);
	if (stops) efree(stops);
}

ZEND_FUNCTION(plutovg_paint_create_radial_gradient)
{
	double cx, cy, cr, fx, fy, fr;
	zend_long spread, nstops;
	HashTable *zstops;
	zval *zm;
	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(cr)
		Z_PARAM_DOUBLE(fx) Z_PARAM_DOUBLE(fy) Z_PARAM_DOUBLE(fr)
		Z_PARAM_LONG(spread)
		Z_PARAM_ARRAY_HT(zstops)
		Z_PARAM_LONG(nstops)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_gradient_stop_t *stops;
	if (!pv_enum(spread, PLUTOVG_SPREAD_METHOD_REPEAT, "PLUTOVG_SPREAD_METHOD_", 7) || !pv_stops(zstops, nstops, &stops, 9)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_radial_gradient((float) cx, (float) cy, (float) cr, (float) fx, (float) fy, (float) fr,
		(plutovg_spread_method_t) spread, stops, (int) nstops, zm ? &m : NULL), NULL, return_value);
	if (stops) efree(stops);
}

ZEND_FUNCTION(plutovg_paint_create_texture)
{
	zval *zs, *zm;
	zend_long type;
	double opacity;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_LONG(type)
		Z_PARAM_DOUBLE(opacity)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	SURFACE_ARG(zs, 1, surface);
	if (!pv_enum(type, PLUTOVG_TEXTURE_TYPE_TILED, "PLUTOVG_TEXTURE_TYPE_", 2)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	pv_handle_wrap(pv_paint_ce, plutovg_paint_create_texture(surface, (plutovg_texture_type_t) type, (float) opacity, zm ? &m : NULL),
		Z_OBJ_P(zs), return_value);
}

ZEND_FUNCTION(plutovg_paint_reference)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_paint_ce)
	ZEND_PARSE_PARAMETERS_END();
	PAINT_ARG(zp, 1, paint);
	pv_handle_wrap(pv_paint_ce, plutovg_paint_reference(paint), Z_OBJ_P(zp), return_value);
}

ZEND_FUNCTION(plutovg_paint_destroy)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_paint_ce)
	ZEND_PARSE_PARAMETERS_END();
	PAINT_ARG(zp, 1, paint);
	(void) paint;
	pv_handle_release(Z_OBJ_P(zp));
}

ZEND_FUNCTION(plutovg_paint_get_reference_count)
{
	zval *zp;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_paint_ce)
	ZEND_PARSE_PARAMETERS_END();
	PAINT_ARG(zp, 1, paint);
	RETURN_LONG(plutovg_paint_get_reference_count(paint));
}
