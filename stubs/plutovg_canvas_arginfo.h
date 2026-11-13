/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1d410000f4385c5fae11faa24bfe65815e98ef66 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_create, 0, 1, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_reference, 0, 1, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_get_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_get_surface, 0, 1, plutovg_surface, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_save arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_restore arginfo_plutovg_canvas_destroy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_rgb, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_rgba, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_color, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_linear_gradient, 0, 9, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, spread, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stops, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, nstops, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_radial_gradient, 0, 11, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_texture, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, surface, plutovg_surface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_paint, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, paint, plutovg_paint, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_get_paint, 0, 2, plutovg_paint, 1)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, color, plutovg_color, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_font_face_cache, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_get_font_face_cache, 0, 1, plutovg_font_face_cache, 1)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_add_font_face, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_add_font_file, 0, 6, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ttcindex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_select_font_face, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_font, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 1)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_font_face, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_get_font_face, 0, 1, plutovg_font_face, 1)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_font_size, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_get_font_size, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_fill_rule, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, winding, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_fill_rule arginfo_plutovg_canvas_get_reference_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_operator, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, op, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_operator arginfo_plutovg_canvas_get_reference_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_opacity, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_opacity arginfo_plutovg_canvas_get_font_size

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_line_width, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, line_width, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_line_width arginfo_plutovg_canvas_get_font_size

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_line_cap, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, line_cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_line_cap arginfo_plutovg_canvas_get_reference_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_line_join, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, line_join, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_line_join arginfo_plutovg_canvas_get_reference_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_miter_limit, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, miter_limit, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_miter_limit arginfo_plutovg_canvas_get_font_size

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_dash, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ndashes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_dash_offset, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_get_dash_offset arginfo_plutovg_canvas_get_font_size

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_set_dash_array, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ndashes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_get_dash_array, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(1, dashes, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_translate, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_scale, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_shear, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, shx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, shy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_rotate, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_transform, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_reset_matrix arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_set_matrix arginfo_plutovg_canvas_transform

#define arginfo_plutovg_canvas_get_matrix arginfo_plutovg_canvas_transform

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_map, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, xx, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, yy, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_map_point, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, src, plutovg_point, 0)
	ZEND_ARG_OBJ_INFO(0, dst, plutovg_point, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_map_rect, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, src, plutovg_rect, 0)
	ZEND_ARG_OBJ_INFO(0, dst, plutovg_rect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_move_to, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_line_to arginfo_plutovg_canvas_move_to

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_quad_to, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_cubic_to, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y3, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_arc_to, 0, 8, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, large_arc_flag, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sweep_flag, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_rect, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_round_rect, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_ellipse, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_circle, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_arc, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ccw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_add_path, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_new_path arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_close_path arginfo_plutovg_canvas_destroy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_get_current_point, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(1, x, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, y, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_canvas_get_path, 0, 1, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_fill_contains, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_stroke_contains arginfo_plutovg_canvas_fill_contains

#define arginfo_plutovg_canvas_clip_contains arginfo_plutovg_canvas_fill_contains

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_fill_extents, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_stroke_extents arginfo_plutovg_canvas_fill_extents

#define arginfo_plutovg_canvas_clip_extents arginfo_plutovg_canvas_fill_extents

#define arginfo_plutovg_canvas_fill arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_stroke arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_clip arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_paint arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_fill_preserve arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_stroke_preserve arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_clip_preserve arginfo_plutovg_canvas_destroy

#define arginfo_plutovg_canvas_fill_rect arginfo_plutovg_canvas_rect

#define arginfo_plutovg_canvas_fill_path arginfo_plutovg_canvas_add_path

#define arginfo_plutovg_canvas_stroke_rect arginfo_plutovg_canvas_rect

#define arginfo_plutovg_canvas_stroke_path arginfo_plutovg_canvas_add_path

#define arginfo_plutovg_canvas_clip_rect arginfo_plutovg_canvas_rect

#define arginfo_plutovg_canvas_clip_path arginfo_plutovg_canvas_add_path

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_add_glyph, 0, 4, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_add_text, 0, 6, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_canvas_fill_text arginfo_plutovg_canvas_add_text

#define arginfo_plutovg_canvas_stroke_text arginfo_plutovg_canvas_add_text

#define arginfo_plutovg_canvas_clip_text arginfo_plutovg_canvas_add_text

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_font_metrics, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(1, ascent, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, descent, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, line_gap, IS_DOUBLE, 1)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_glyph_metrics, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, advance_width, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, left_side_bearing, IS_DOUBLE, 1)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_canvas_text_extents, 0, 5, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, canvas, plutovg_canvas, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(plutovg_canvas_create);
ZEND_FUNCTION(plutovg_canvas_reference);
ZEND_FUNCTION(plutovg_canvas_destroy);
ZEND_FUNCTION(plutovg_canvas_get_reference_count);
ZEND_FUNCTION(plutovg_canvas_get_surface);
ZEND_FUNCTION(plutovg_canvas_save);
ZEND_FUNCTION(plutovg_canvas_restore);
ZEND_FUNCTION(plutovg_canvas_set_rgb);
ZEND_FUNCTION(plutovg_canvas_set_rgba);
ZEND_FUNCTION(plutovg_canvas_set_color);
ZEND_FUNCTION(plutovg_canvas_set_linear_gradient);
ZEND_FUNCTION(plutovg_canvas_set_radial_gradient);
ZEND_FUNCTION(plutovg_canvas_set_texture);
ZEND_FUNCTION(plutovg_canvas_set_paint);
ZEND_FUNCTION(plutovg_canvas_get_paint);
ZEND_FUNCTION(plutovg_canvas_set_font_face_cache);
ZEND_FUNCTION(plutovg_canvas_get_font_face_cache);
ZEND_FUNCTION(plutovg_canvas_add_font_face);
ZEND_FUNCTION(plutovg_canvas_add_font_file);
ZEND_FUNCTION(plutovg_canvas_select_font_face);
ZEND_FUNCTION(plutovg_canvas_set_font);
ZEND_FUNCTION(plutovg_canvas_set_font_face);
ZEND_FUNCTION(plutovg_canvas_get_font_face);
ZEND_FUNCTION(plutovg_canvas_set_font_size);
ZEND_FUNCTION(plutovg_canvas_get_font_size);
ZEND_FUNCTION(plutovg_canvas_set_fill_rule);
ZEND_FUNCTION(plutovg_canvas_get_fill_rule);
ZEND_FUNCTION(plutovg_canvas_set_operator);
ZEND_FUNCTION(plutovg_canvas_get_operator);
ZEND_FUNCTION(plutovg_canvas_set_opacity);
ZEND_FUNCTION(plutovg_canvas_get_opacity);
ZEND_FUNCTION(plutovg_canvas_set_line_width);
ZEND_FUNCTION(plutovg_canvas_get_line_width);
ZEND_FUNCTION(plutovg_canvas_set_line_cap);
ZEND_FUNCTION(plutovg_canvas_get_line_cap);
ZEND_FUNCTION(plutovg_canvas_set_line_join);
ZEND_FUNCTION(plutovg_canvas_get_line_join);
ZEND_FUNCTION(plutovg_canvas_set_miter_limit);
ZEND_FUNCTION(plutovg_canvas_get_miter_limit);
ZEND_FUNCTION(plutovg_canvas_set_dash);
ZEND_FUNCTION(plutovg_canvas_set_dash_offset);
ZEND_FUNCTION(plutovg_canvas_get_dash_offset);
ZEND_FUNCTION(plutovg_canvas_set_dash_array);
ZEND_FUNCTION(plutovg_canvas_get_dash_array);
ZEND_FUNCTION(plutovg_canvas_translate);
ZEND_FUNCTION(plutovg_canvas_scale);
ZEND_FUNCTION(plutovg_canvas_shear);
ZEND_FUNCTION(plutovg_canvas_rotate);
ZEND_FUNCTION(plutovg_canvas_transform);
ZEND_FUNCTION(plutovg_canvas_reset_matrix);
ZEND_FUNCTION(plutovg_canvas_set_matrix);
ZEND_FUNCTION(plutovg_canvas_get_matrix);
ZEND_FUNCTION(plutovg_canvas_map);
ZEND_FUNCTION(plutovg_canvas_map_point);
ZEND_FUNCTION(plutovg_canvas_map_rect);
ZEND_FUNCTION(plutovg_canvas_move_to);
ZEND_FUNCTION(plutovg_canvas_line_to);
ZEND_FUNCTION(plutovg_canvas_quad_to);
ZEND_FUNCTION(plutovg_canvas_cubic_to);
ZEND_FUNCTION(plutovg_canvas_arc_to);
ZEND_FUNCTION(plutovg_canvas_rect);
ZEND_FUNCTION(plutovg_canvas_round_rect);
ZEND_FUNCTION(plutovg_canvas_ellipse);
ZEND_FUNCTION(plutovg_canvas_circle);
ZEND_FUNCTION(plutovg_canvas_arc);
ZEND_FUNCTION(plutovg_canvas_add_path);
ZEND_FUNCTION(plutovg_canvas_new_path);
ZEND_FUNCTION(plutovg_canvas_close_path);
ZEND_FUNCTION(plutovg_canvas_get_current_point);
ZEND_FUNCTION(plutovg_canvas_get_path);
ZEND_FUNCTION(plutovg_canvas_fill_contains);
ZEND_FUNCTION(plutovg_canvas_stroke_contains);
ZEND_FUNCTION(plutovg_canvas_clip_contains);
ZEND_FUNCTION(plutovg_canvas_fill_extents);
ZEND_FUNCTION(plutovg_canvas_stroke_extents);
ZEND_FUNCTION(plutovg_canvas_clip_extents);
ZEND_FUNCTION(plutovg_canvas_fill);
ZEND_FUNCTION(plutovg_canvas_stroke);
ZEND_FUNCTION(plutovg_canvas_clip);
ZEND_FUNCTION(plutovg_canvas_paint);
ZEND_FUNCTION(plutovg_canvas_fill_preserve);
ZEND_FUNCTION(plutovg_canvas_stroke_preserve);
ZEND_FUNCTION(plutovg_canvas_clip_preserve);
ZEND_FUNCTION(plutovg_canvas_fill_rect);
ZEND_FUNCTION(plutovg_canvas_fill_path);
ZEND_FUNCTION(plutovg_canvas_stroke_rect);
ZEND_FUNCTION(plutovg_canvas_stroke_path);
ZEND_FUNCTION(plutovg_canvas_clip_rect);
ZEND_FUNCTION(plutovg_canvas_clip_path);
ZEND_FUNCTION(plutovg_canvas_add_glyph);
ZEND_FUNCTION(plutovg_canvas_add_text);
ZEND_FUNCTION(plutovg_canvas_fill_text);
ZEND_FUNCTION(plutovg_canvas_stroke_text);
ZEND_FUNCTION(plutovg_canvas_clip_text);
ZEND_FUNCTION(plutovg_canvas_font_metrics);
ZEND_FUNCTION(plutovg_canvas_glyph_metrics);
ZEND_FUNCTION(plutovg_canvas_text_extents);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(plutovg_canvas_create, arginfo_plutovg_canvas_create)
	ZEND_FE(plutovg_canvas_reference, arginfo_plutovg_canvas_reference)
	ZEND_FE(plutovg_canvas_destroy, arginfo_plutovg_canvas_destroy)
	ZEND_FE(plutovg_canvas_get_reference_count, arginfo_plutovg_canvas_get_reference_count)
	ZEND_FE(plutovg_canvas_get_surface, arginfo_plutovg_canvas_get_surface)
	ZEND_FE(plutovg_canvas_save, arginfo_plutovg_canvas_save)
	ZEND_FE(plutovg_canvas_restore, arginfo_plutovg_canvas_restore)
	ZEND_FE(plutovg_canvas_set_rgb, arginfo_plutovg_canvas_set_rgb)
	ZEND_FE(plutovg_canvas_set_rgba, arginfo_plutovg_canvas_set_rgba)
	ZEND_FE(plutovg_canvas_set_color, arginfo_plutovg_canvas_set_color)
	ZEND_FE(plutovg_canvas_set_linear_gradient, arginfo_plutovg_canvas_set_linear_gradient)
	ZEND_FE(plutovg_canvas_set_radial_gradient, arginfo_plutovg_canvas_set_radial_gradient)
	ZEND_FE(plutovg_canvas_set_texture, arginfo_plutovg_canvas_set_texture)
	ZEND_FE(plutovg_canvas_set_paint, arginfo_plutovg_canvas_set_paint)
	ZEND_FE(plutovg_canvas_get_paint, arginfo_plutovg_canvas_get_paint)
	ZEND_FE(plutovg_canvas_set_font_face_cache, arginfo_plutovg_canvas_set_font_face_cache)
	ZEND_FE(plutovg_canvas_get_font_face_cache, arginfo_plutovg_canvas_get_font_face_cache)
	ZEND_FE(plutovg_canvas_add_font_face, arginfo_plutovg_canvas_add_font_face)
	ZEND_FE(plutovg_canvas_add_font_file, arginfo_plutovg_canvas_add_font_file)
	ZEND_FE(plutovg_canvas_select_font_face, arginfo_plutovg_canvas_select_font_face)
	ZEND_FE(plutovg_canvas_set_font, arginfo_plutovg_canvas_set_font)
	ZEND_FE(plutovg_canvas_set_font_face, arginfo_plutovg_canvas_set_font_face)
	ZEND_FE(plutovg_canvas_get_font_face, arginfo_plutovg_canvas_get_font_face)
	ZEND_FE(plutovg_canvas_set_font_size, arginfo_plutovg_canvas_set_font_size)
	ZEND_FE(plutovg_canvas_get_font_size, arginfo_plutovg_canvas_get_font_size)
	ZEND_FE(plutovg_canvas_set_fill_rule, arginfo_plutovg_canvas_set_fill_rule)
	ZEND_FE(plutovg_canvas_get_fill_rule, arginfo_plutovg_canvas_get_fill_rule)
	ZEND_FE(plutovg_canvas_set_operator, arginfo_plutovg_canvas_set_operator)
	ZEND_FE(plutovg_canvas_get_operator, arginfo_plutovg_canvas_get_operator)
	ZEND_FE(plutovg_canvas_set_opacity, arginfo_plutovg_canvas_set_opacity)
	ZEND_FE(plutovg_canvas_get_opacity, arginfo_plutovg_canvas_get_opacity)
	ZEND_FE(plutovg_canvas_set_line_width, arginfo_plutovg_canvas_set_line_width)
	ZEND_FE(plutovg_canvas_get_line_width, arginfo_plutovg_canvas_get_line_width)
	ZEND_FE(plutovg_canvas_set_line_cap, arginfo_plutovg_canvas_set_line_cap)
	ZEND_FE(plutovg_canvas_get_line_cap, arginfo_plutovg_canvas_get_line_cap)
	ZEND_FE(plutovg_canvas_set_line_join, arginfo_plutovg_canvas_set_line_join)
	ZEND_FE(plutovg_canvas_get_line_join, arginfo_plutovg_canvas_get_line_join)
	ZEND_FE(plutovg_canvas_set_miter_limit, arginfo_plutovg_canvas_set_miter_limit)
	ZEND_FE(plutovg_canvas_get_miter_limit, arginfo_plutovg_canvas_get_miter_limit)
	ZEND_FE(plutovg_canvas_set_dash, arginfo_plutovg_canvas_set_dash)
	ZEND_FE(plutovg_canvas_set_dash_offset, arginfo_plutovg_canvas_set_dash_offset)
	ZEND_FE(plutovg_canvas_get_dash_offset, arginfo_plutovg_canvas_get_dash_offset)
	ZEND_FE(plutovg_canvas_set_dash_array, arginfo_plutovg_canvas_set_dash_array)
	ZEND_FE(plutovg_canvas_get_dash_array, arginfo_plutovg_canvas_get_dash_array)
	ZEND_FE(plutovg_canvas_translate, arginfo_plutovg_canvas_translate)
	ZEND_FE(plutovg_canvas_scale, arginfo_plutovg_canvas_scale)
	ZEND_FE(plutovg_canvas_shear, arginfo_plutovg_canvas_shear)
	ZEND_FE(plutovg_canvas_rotate, arginfo_plutovg_canvas_rotate)
	ZEND_FE(plutovg_canvas_transform, arginfo_plutovg_canvas_transform)
	ZEND_FE(plutovg_canvas_reset_matrix, arginfo_plutovg_canvas_reset_matrix)
	ZEND_FE(plutovg_canvas_set_matrix, arginfo_plutovg_canvas_set_matrix)
	ZEND_FE(plutovg_canvas_get_matrix, arginfo_plutovg_canvas_get_matrix)
	ZEND_FE(plutovg_canvas_map, arginfo_plutovg_canvas_map)
	ZEND_FE(plutovg_canvas_map_point, arginfo_plutovg_canvas_map_point)
	ZEND_FE(plutovg_canvas_map_rect, arginfo_plutovg_canvas_map_rect)
	ZEND_FE(plutovg_canvas_move_to, arginfo_plutovg_canvas_move_to)
	ZEND_FE(plutovg_canvas_line_to, arginfo_plutovg_canvas_line_to)
	ZEND_FE(plutovg_canvas_quad_to, arginfo_plutovg_canvas_quad_to)
	ZEND_FE(plutovg_canvas_cubic_to, arginfo_plutovg_canvas_cubic_to)
	ZEND_FE(plutovg_canvas_arc_to, arginfo_plutovg_canvas_arc_to)
	ZEND_FE(plutovg_canvas_rect, arginfo_plutovg_canvas_rect)
	ZEND_FE(plutovg_canvas_round_rect, arginfo_plutovg_canvas_round_rect)
	ZEND_FE(plutovg_canvas_ellipse, arginfo_plutovg_canvas_ellipse)
	ZEND_FE(plutovg_canvas_circle, arginfo_plutovg_canvas_circle)
	ZEND_FE(plutovg_canvas_arc, arginfo_plutovg_canvas_arc)
	ZEND_FE(plutovg_canvas_add_path, arginfo_plutovg_canvas_add_path)
	ZEND_FE(plutovg_canvas_new_path, arginfo_plutovg_canvas_new_path)
	ZEND_FE(plutovg_canvas_close_path, arginfo_plutovg_canvas_close_path)
	ZEND_FE(plutovg_canvas_get_current_point, arginfo_plutovg_canvas_get_current_point)
	ZEND_FE(plutovg_canvas_get_path, arginfo_plutovg_canvas_get_path)
	ZEND_FE(plutovg_canvas_fill_contains, arginfo_plutovg_canvas_fill_contains)
	ZEND_FE(plutovg_canvas_stroke_contains, arginfo_plutovg_canvas_stroke_contains)
	ZEND_FE(plutovg_canvas_clip_contains, arginfo_plutovg_canvas_clip_contains)
	ZEND_FE(plutovg_canvas_fill_extents, arginfo_plutovg_canvas_fill_extents)
	ZEND_FE(plutovg_canvas_stroke_extents, arginfo_plutovg_canvas_stroke_extents)
	ZEND_FE(plutovg_canvas_clip_extents, arginfo_plutovg_canvas_clip_extents)
	ZEND_FE(plutovg_canvas_fill, arginfo_plutovg_canvas_fill)
	ZEND_FE(plutovg_canvas_stroke, arginfo_plutovg_canvas_stroke)
	ZEND_FE(plutovg_canvas_clip, arginfo_plutovg_canvas_clip)
	ZEND_FE(plutovg_canvas_paint, arginfo_plutovg_canvas_paint)
	ZEND_FE(plutovg_canvas_fill_preserve, arginfo_plutovg_canvas_fill_preserve)
	ZEND_FE(plutovg_canvas_stroke_preserve, arginfo_plutovg_canvas_stroke_preserve)
	ZEND_FE(plutovg_canvas_clip_preserve, arginfo_plutovg_canvas_clip_preserve)
	ZEND_FE(plutovg_canvas_fill_rect, arginfo_plutovg_canvas_fill_rect)
	ZEND_FE(plutovg_canvas_fill_path, arginfo_plutovg_canvas_fill_path)
	ZEND_FE(plutovg_canvas_stroke_rect, arginfo_plutovg_canvas_stroke_rect)
	ZEND_FE(plutovg_canvas_stroke_path, arginfo_plutovg_canvas_stroke_path)
	ZEND_FE(plutovg_canvas_clip_rect, arginfo_plutovg_canvas_clip_rect)
	ZEND_FE(plutovg_canvas_clip_path, arginfo_plutovg_canvas_clip_path)
	ZEND_FE(plutovg_canvas_add_glyph, arginfo_plutovg_canvas_add_glyph)
	ZEND_FE(plutovg_canvas_add_text, arginfo_plutovg_canvas_add_text)
	ZEND_FE(plutovg_canvas_fill_text, arginfo_plutovg_canvas_fill_text)
	ZEND_FE(plutovg_canvas_stroke_text, arginfo_plutovg_canvas_stroke_text)
	ZEND_FE(plutovg_canvas_clip_text, arginfo_plutovg_canvas_clip_text)
	ZEND_FE(plutovg_canvas_font_metrics, arginfo_plutovg_canvas_font_metrics)
	ZEND_FE(plutovg_canvas_glyph_metrics, arginfo_plutovg_canvas_glyph_metrics)
	ZEND_FE(plutovg_canvas_text_extents, arginfo_plutovg_canvas_text_extents)
	ZEND_FE_END
};
