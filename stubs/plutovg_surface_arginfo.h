/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6d0f05ea3fab748634cbe068b90b7411cde5678f */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_rgb, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_rgba, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_rgb8, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_rgba8, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_rgba32, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_color_init_argb32 arginfo_plutovg_color_init_rgba32

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_hsl, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, l, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_init_hsla, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, l, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_to_rgba32, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_color_to_argb32 arginfo_plutovg_color_to_rgba32

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_color_parse, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_create, 0, 2, plutovg_surface, 1)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_create_for_data, 0, 4, plutovg_surface, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_create_for_address, 0, 5, plutovg_surface, 1)
	ZEND_ARG_TYPE_INFO(0, address, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, owner, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_load_from_image_file, 0, 1, plutovg_surface, 1)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_load_from_image_data, 0, 2, plutovg_surface, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_surface_load_from_image_base64 arginfo_plutovg_surface_load_from_image_data

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_surface_reference, 0, 1, plutovg_surface, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_get_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_get_data, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_surface_get_data_address arginfo_plutovg_surface_get_reference_count

#define arginfo_plutovg_surface_get_alpha arginfo_plutovg_surface_get_data

#define arginfo_plutovg_surface_get_width arginfo_plutovg_surface_get_reference_count

#define arginfo_plutovg_surface_get_height arginfo_plutovg_surface_get_reference_count

#define arginfo_plutovg_surface_get_stride arginfo_plutovg_surface_get_reference_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_clear, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_write_to_png, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_write_to_jpg, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_write_to_png_stream, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, write_func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_surface_write_to_jpg_stream, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, write_func, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_convert_argb_to_rgba, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, dst, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, src, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_convert_rgba_to_argb arginfo_plutovg_convert_argb_to_rgba

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_rgb, 0, 3, plutovg_paint, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_rgba, 0, 4, plutovg_paint, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_color, 0, 1, plutovg_paint, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_linear_gradient, 0, 8, plutovg_paint, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, spread, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stops, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, nstops, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_radial_gradient, 0, 10, plutovg_paint, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cr, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, fx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, fy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, fr, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, spread, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stops, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, nstops, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_create_texture, 0, 4, plutovg_paint, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_paint_reference, 0, 1, plutovg_paint, 0)
	ZEND_ARG_OBJ_INFO(0, paint, plutovg_paint, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_paint_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, paint, plutovg_paint, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_paint_get_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, paint, plutovg_paint, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(plutovg_color_init_rgb);
ZEND_FUNCTION(plutovg_color_init_rgba);
ZEND_FUNCTION(plutovg_color_init_rgb8);
ZEND_FUNCTION(plutovg_color_init_rgba8);
ZEND_FUNCTION(plutovg_color_init_rgba32);
ZEND_FUNCTION(plutovg_color_init_argb32);
ZEND_FUNCTION(plutovg_color_init_hsl);
ZEND_FUNCTION(plutovg_color_init_hsla);
ZEND_FUNCTION(plutovg_color_to_rgba32);
ZEND_FUNCTION(plutovg_color_to_argb32);
ZEND_FUNCTION(plutovg_color_parse);
ZEND_FUNCTION(plutovg_surface_create);
ZEND_FUNCTION(plutovg_surface_create_for_data);
ZEND_FUNCTION(plutovg_surface_create_for_address);
ZEND_FUNCTION(plutovg_surface_load_from_image_file);
ZEND_FUNCTION(plutovg_surface_load_from_image_data);
ZEND_FUNCTION(plutovg_surface_load_from_image_base64);
ZEND_FUNCTION(plutovg_surface_reference);
ZEND_FUNCTION(plutovg_surface_destroy);
ZEND_FUNCTION(plutovg_surface_get_reference_count);
ZEND_FUNCTION(plutovg_surface_get_data);
ZEND_FUNCTION(plutovg_surface_get_data_address);
ZEND_FUNCTION(plutovg_surface_get_alpha);
ZEND_FUNCTION(plutovg_surface_get_width);
ZEND_FUNCTION(plutovg_surface_get_height);
ZEND_FUNCTION(plutovg_surface_get_stride);
ZEND_FUNCTION(plutovg_surface_clear);
ZEND_FUNCTION(plutovg_surface_write_to_png);
ZEND_FUNCTION(plutovg_surface_write_to_jpg);
ZEND_FUNCTION(plutovg_surface_write_to_png_stream);
ZEND_FUNCTION(plutovg_surface_write_to_jpg_stream);
ZEND_FUNCTION(plutovg_convert_argb_to_rgba);
ZEND_FUNCTION(plutovg_convert_rgba_to_argb);
ZEND_FUNCTION(plutovg_paint_create_rgb);
ZEND_FUNCTION(plutovg_paint_create_rgba);
ZEND_FUNCTION(plutovg_paint_create_color);
ZEND_FUNCTION(plutovg_paint_create_linear_gradient);
ZEND_FUNCTION(plutovg_paint_create_radial_gradient);
ZEND_FUNCTION(plutovg_paint_create_texture);
ZEND_FUNCTION(plutovg_paint_reference);
ZEND_FUNCTION(plutovg_paint_destroy);
ZEND_FUNCTION(plutovg_paint_get_reference_count);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(plutovg_color_init_rgb, arginfo_plutovg_color_init_rgb)
	ZEND_FE(plutovg_color_init_rgba, arginfo_plutovg_color_init_rgba)
	ZEND_FE(plutovg_color_init_rgb8, arginfo_plutovg_color_init_rgb8)
	ZEND_FE(plutovg_color_init_rgba8, arginfo_plutovg_color_init_rgba8)
	ZEND_FE(plutovg_color_init_rgba32, arginfo_plutovg_color_init_rgba32)
	ZEND_FE(plutovg_color_init_argb32, arginfo_plutovg_color_init_argb32)
	ZEND_FE(plutovg_color_init_hsl, arginfo_plutovg_color_init_hsl)
	ZEND_FE(plutovg_color_init_hsla, arginfo_plutovg_color_init_hsla)
	ZEND_FE(plutovg_color_to_rgba32, arginfo_plutovg_color_to_rgba32)
	ZEND_FE(plutovg_color_to_argb32, arginfo_plutovg_color_to_argb32)
	ZEND_FE(plutovg_color_parse, arginfo_plutovg_color_parse)
	ZEND_FE(plutovg_surface_create, arginfo_plutovg_surface_create)
	ZEND_FE(plutovg_surface_create_for_data, arginfo_plutovg_surface_create_for_data)
	ZEND_FE(plutovg_surface_create_for_address, arginfo_plutovg_surface_create_for_address)
	ZEND_FE(plutovg_surface_load_from_image_file, arginfo_plutovg_surface_load_from_image_file)
	ZEND_FE(plutovg_surface_load_from_image_data, arginfo_plutovg_surface_load_from_image_data)
	ZEND_FE(plutovg_surface_load_from_image_base64, arginfo_plutovg_surface_load_from_image_base64)
	ZEND_FE(plutovg_surface_reference, arginfo_plutovg_surface_reference)
	ZEND_FE(plutovg_surface_destroy, arginfo_plutovg_surface_destroy)
	ZEND_FE(plutovg_surface_get_reference_count, arginfo_plutovg_surface_get_reference_count)
	ZEND_FE(plutovg_surface_get_data, arginfo_plutovg_surface_get_data)
	ZEND_FE(plutovg_surface_get_data_address, arginfo_plutovg_surface_get_data_address)
	ZEND_FE(plutovg_surface_get_alpha, arginfo_plutovg_surface_get_alpha)
	ZEND_FE(plutovg_surface_get_width, arginfo_plutovg_surface_get_width)
	ZEND_FE(plutovg_surface_get_height, arginfo_plutovg_surface_get_height)
	ZEND_FE(plutovg_surface_get_stride, arginfo_plutovg_surface_get_stride)
	ZEND_FE(plutovg_surface_clear, arginfo_plutovg_surface_clear)
	ZEND_FE(plutovg_surface_write_to_png, arginfo_plutovg_surface_write_to_png)
	ZEND_FE(plutovg_surface_write_to_jpg, arginfo_plutovg_surface_write_to_jpg)
	ZEND_FE(plutovg_surface_write_to_png_stream, arginfo_plutovg_surface_write_to_png_stream)
	ZEND_FE(plutovg_surface_write_to_jpg_stream, arginfo_plutovg_surface_write_to_jpg_stream)
	ZEND_FE(plutovg_convert_argb_to_rgba, arginfo_plutovg_convert_argb_to_rgba)
	ZEND_FE(plutovg_convert_rgba_to_argb, arginfo_plutovg_convert_rgba_to_argb)
	ZEND_FE(plutovg_paint_create_rgb, arginfo_plutovg_paint_create_rgb)
	ZEND_FE(plutovg_paint_create_rgba, arginfo_plutovg_paint_create_rgba)
	ZEND_FE(plutovg_paint_create_color, arginfo_plutovg_paint_create_color)
	ZEND_FE(plutovg_paint_create_linear_gradient, arginfo_plutovg_paint_create_linear_gradient)
	ZEND_FE(plutovg_paint_create_radial_gradient, arginfo_plutovg_paint_create_radial_gradient)
	ZEND_FE(plutovg_paint_create_texture, arginfo_plutovg_paint_create_texture)
	ZEND_FE(plutovg_paint_reference, arginfo_plutovg_paint_reference)
	ZEND_FE(plutovg_paint_destroy, arginfo_plutovg_paint_destroy)
	ZEND_FE(plutovg_paint_get_reference_count, arginfo_plutovg_paint_get_reference_count)
	ZEND_FE_END
};
