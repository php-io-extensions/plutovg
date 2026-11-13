/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 85b0167a87ae5ef2c23ed0e999f20ee695098d7b */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, c, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, d, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, e, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, f, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init_identity, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init_translate, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init_scale, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init_rotate, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_init_shear, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, shx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, shy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_matrix_translate arginfo_plutovg_matrix_init_translate

#define arginfo_plutovg_matrix_scale arginfo_plutovg_matrix_init_scale

#define arginfo_plutovg_matrix_rotate arginfo_plutovg_matrix_init_rotate

#define arginfo_plutovg_matrix_shear arginfo_plutovg_matrix_init_shear

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_multiply, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_OBJ_INFO(0, left, plutovg_matrix, 0)
	ZEND_ARG_OBJ_INFO(0, right, plutovg_matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_invert, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_OBJ_INFO(0, inverse, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_map, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, xx, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, yy, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_map_point, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_OBJ_INFO(0, src, plutovg_point, 0)
	ZEND_ARG_OBJ_INFO(0, dst, plutovg_point, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_map_points, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, src, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(1, dst, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_map_rect, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_OBJ_INFO(0, src, plutovg_rect, 0)
	ZEND_ARG_OBJ_INFO(0, dst, plutovg_rect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_matrix_parse, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_iterator_init, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_path_iterator, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_iterator_has_next, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_path_iterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_iterator_next, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_path_iterator, 0)
	ZEND_ARG_TYPE_INFO(1, points, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_path_create, 0, 0, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_path_reference, 0, 1, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_get_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_get_elements, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(1, elements, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_move_to, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_path_line_to arginfo_plutovg_path_move_to

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_quad_to, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_cubic_to, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y3, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_arc_to, 0, 8, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, large_arc_flag, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sweep_flag, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_path_close arginfo_plutovg_path_destroy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_get_current_point, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(1, x, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, y, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_reserve, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_path_reset arginfo_plutovg_path_destroy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_rect, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_round_rect, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_ellipse, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_circle, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_arc, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, cx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, cy, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ccw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_add_path, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, source, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_transform, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, plutovg_matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_traverse, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, traverse_func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_path_traverse_flatten arginfo_plutovg_path_traverse

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_traverse_dashed, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ndashes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, traverse_func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_path_clone arginfo_plutovg_path_reference

#define arginfo_plutovg_path_clone_flatten arginfo_plutovg_path_reference

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_path_clone_dashed, 0, 4, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ndashes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_extents, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
	ZEND_ARG_TYPE_INFO(0, tight, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_length, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_path_parse, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_text_iterator_init, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_text_iterator, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_text_iterator_has_next, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_text_iterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_text_iterator_next, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, it, plutovg_text_iterator, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(plutovg_matrix_init);
ZEND_FUNCTION(plutovg_matrix_init_identity);
ZEND_FUNCTION(plutovg_matrix_init_translate);
ZEND_FUNCTION(plutovg_matrix_init_scale);
ZEND_FUNCTION(plutovg_matrix_init_rotate);
ZEND_FUNCTION(plutovg_matrix_init_shear);
ZEND_FUNCTION(plutovg_matrix_translate);
ZEND_FUNCTION(plutovg_matrix_scale);
ZEND_FUNCTION(plutovg_matrix_rotate);
ZEND_FUNCTION(plutovg_matrix_shear);
ZEND_FUNCTION(plutovg_matrix_multiply);
ZEND_FUNCTION(plutovg_matrix_invert);
ZEND_FUNCTION(plutovg_matrix_map);
ZEND_FUNCTION(plutovg_matrix_map_point);
ZEND_FUNCTION(plutovg_matrix_map_points);
ZEND_FUNCTION(plutovg_matrix_map_rect);
ZEND_FUNCTION(plutovg_matrix_parse);
ZEND_FUNCTION(plutovg_path_iterator_init);
ZEND_FUNCTION(plutovg_path_iterator_has_next);
ZEND_FUNCTION(plutovg_path_iterator_next);
ZEND_FUNCTION(plutovg_path_create);
ZEND_FUNCTION(plutovg_path_reference);
ZEND_FUNCTION(plutovg_path_destroy);
ZEND_FUNCTION(plutovg_path_get_reference_count);
ZEND_FUNCTION(plutovg_path_get_elements);
ZEND_FUNCTION(plutovg_path_move_to);
ZEND_FUNCTION(plutovg_path_line_to);
ZEND_FUNCTION(plutovg_path_quad_to);
ZEND_FUNCTION(plutovg_path_cubic_to);
ZEND_FUNCTION(plutovg_path_arc_to);
ZEND_FUNCTION(plutovg_path_close);
ZEND_FUNCTION(plutovg_path_get_current_point);
ZEND_FUNCTION(plutovg_path_reserve);
ZEND_FUNCTION(plutovg_path_reset);
ZEND_FUNCTION(plutovg_path_add_rect);
ZEND_FUNCTION(plutovg_path_add_round_rect);
ZEND_FUNCTION(plutovg_path_add_ellipse);
ZEND_FUNCTION(plutovg_path_add_circle);
ZEND_FUNCTION(plutovg_path_add_arc);
ZEND_FUNCTION(plutovg_path_add_path);
ZEND_FUNCTION(plutovg_path_transform);
ZEND_FUNCTION(plutovg_path_traverse);
ZEND_FUNCTION(plutovg_path_traverse_flatten);
ZEND_FUNCTION(plutovg_path_traverse_dashed);
ZEND_FUNCTION(plutovg_path_clone);
ZEND_FUNCTION(plutovg_path_clone_flatten);
ZEND_FUNCTION(plutovg_path_clone_dashed);
ZEND_FUNCTION(plutovg_path_extents);
ZEND_FUNCTION(plutovg_path_length);
ZEND_FUNCTION(plutovg_path_parse);
ZEND_FUNCTION(plutovg_text_iterator_init);
ZEND_FUNCTION(plutovg_text_iterator_has_next);
ZEND_FUNCTION(plutovg_text_iterator_next);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(plutovg_matrix_init, arginfo_plutovg_matrix_init)
	ZEND_FE(plutovg_matrix_init_identity, arginfo_plutovg_matrix_init_identity)
	ZEND_FE(plutovg_matrix_init_translate, arginfo_plutovg_matrix_init_translate)
	ZEND_FE(plutovg_matrix_init_scale, arginfo_plutovg_matrix_init_scale)
	ZEND_FE(plutovg_matrix_init_rotate, arginfo_plutovg_matrix_init_rotate)
	ZEND_FE(plutovg_matrix_init_shear, arginfo_plutovg_matrix_init_shear)
	ZEND_FE(plutovg_matrix_translate, arginfo_plutovg_matrix_translate)
	ZEND_FE(plutovg_matrix_scale, arginfo_plutovg_matrix_scale)
	ZEND_FE(plutovg_matrix_rotate, arginfo_plutovg_matrix_rotate)
	ZEND_FE(plutovg_matrix_shear, arginfo_plutovg_matrix_shear)
	ZEND_FE(plutovg_matrix_multiply, arginfo_plutovg_matrix_multiply)
	ZEND_FE(plutovg_matrix_invert, arginfo_plutovg_matrix_invert)
	ZEND_FE(plutovg_matrix_map, arginfo_plutovg_matrix_map)
	ZEND_FE(plutovg_matrix_map_point, arginfo_plutovg_matrix_map_point)
	ZEND_FE(plutovg_matrix_map_points, arginfo_plutovg_matrix_map_points)
	ZEND_FE(plutovg_matrix_map_rect, arginfo_plutovg_matrix_map_rect)
	ZEND_FE(plutovg_matrix_parse, arginfo_plutovg_matrix_parse)
	ZEND_FE(plutovg_path_iterator_init, arginfo_plutovg_path_iterator_init)
	ZEND_FE(plutovg_path_iterator_has_next, arginfo_plutovg_path_iterator_has_next)
	ZEND_FE(plutovg_path_iterator_next, arginfo_plutovg_path_iterator_next)
	ZEND_FE(plutovg_path_create, arginfo_plutovg_path_create)
	ZEND_FE(plutovg_path_reference, arginfo_plutovg_path_reference)
	ZEND_FE(plutovg_path_destroy, arginfo_plutovg_path_destroy)
	ZEND_FE(plutovg_path_get_reference_count, arginfo_plutovg_path_get_reference_count)
	ZEND_FE(plutovg_path_get_elements, arginfo_plutovg_path_get_elements)
	ZEND_FE(plutovg_path_move_to, arginfo_plutovg_path_move_to)
	ZEND_FE(plutovg_path_line_to, arginfo_plutovg_path_line_to)
	ZEND_FE(plutovg_path_quad_to, arginfo_plutovg_path_quad_to)
	ZEND_FE(plutovg_path_cubic_to, arginfo_plutovg_path_cubic_to)
	ZEND_FE(plutovg_path_arc_to, arginfo_plutovg_path_arc_to)
	ZEND_FE(plutovg_path_close, arginfo_plutovg_path_close)
	ZEND_FE(plutovg_path_get_current_point, arginfo_plutovg_path_get_current_point)
	ZEND_FE(plutovg_path_reserve, arginfo_plutovg_path_reserve)
	ZEND_FE(plutovg_path_reset, arginfo_plutovg_path_reset)
	ZEND_FE(plutovg_path_add_rect, arginfo_plutovg_path_add_rect)
	ZEND_FE(plutovg_path_add_round_rect, arginfo_plutovg_path_add_round_rect)
	ZEND_FE(plutovg_path_add_ellipse, arginfo_plutovg_path_add_ellipse)
	ZEND_FE(plutovg_path_add_circle, arginfo_plutovg_path_add_circle)
	ZEND_FE(plutovg_path_add_arc, arginfo_plutovg_path_add_arc)
	ZEND_FE(plutovg_path_add_path, arginfo_plutovg_path_add_path)
	ZEND_FE(plutovg_path_transform, arginfo_plutovg_path_transform)
	ZEND_FE(plutovg_path_traverse, arginfo_plutovg_path_traverse)
	ZEND_FE(plutovg_path_traverse_flatten, arginfo_plutovg_path_traverse_flatten)
	ZEND_FE(plutovg_path_traverse_dashed, arginfo_plutovg_path_traverse_dashed)
	ZEND_FE(plutovg_path_clone, arginfo_plutovg_path_clone)
	ZEND_FE(plutovg_path_clone_flatten, arginfo_plutovg_path_clone_flatten)
	ZEND_FE(plutovg_path_clone_dashed, arginfo_plutovg_path_clone_dashed)
	ZEND_FE(plutovg_path_extents, arginfo_plutovg_path_extents)
	ZEND_FE(plutovg_path_length, arginfo_plutovg_path_length)
	ZEND_FE(plutovg_path_parse, arginfo_plutovg_path_parse)
	ZEND_FE(plutovg_text_iterator_init, arginfo_plutovg_text_iterator_init)
	ZEND_FE(plutovg_text_iterator_has_next, arginfo_plutovg_text_iterator_has_next)
	ZEND_FE(plutovg_text_iterator_next, arginfo_plutovg_text_iterator_next)
	ZEND_FE_END
};
