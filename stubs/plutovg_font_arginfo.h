/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 60a1f3520f8188d51267d6f8edf1d1954917c067 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_load_from_file, 0, 2, plutovg_font_face, 1)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ttcindex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_load_from_data, 0, 3, plutovg_font_face, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ttcindex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_reference, 0, 1, plutovg_font_face, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_get_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_get_metrics, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, ascent, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, descent, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, line_gap, IS_DOUBLE, 1)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_get_glyph_metrics, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, advance_width, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, left_side_bearing, IS_DOUBLE, 1)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_get_glyph_path, 0, 6, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, path, plutovg_path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_traverse_glyph_path, 0, 6, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, traverse_func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_text_extents, 0, 6, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, extents, plutovg_rect, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_cache_create, 0, 0, plutovg_font_face_cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_cache_reference, 0, 1, plutovg_font_face_cache, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_reference_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_font_face_cache_reset arginfo_plutovg_font_face_cache_destroy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_add, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, face, plutovg_font_face, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_add_file, 0, 6, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ttcindex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_plutovg_font_face_cache_get, 0, 4, plutovg_font_face, 1)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bold, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, italic, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_load_file, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_plutovg_font_face_cache_load_dir, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, cache, plutovg_font_face_cache, 0)
	ZEND_ARG_TYPE_INFO(0, dirname, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_plutovg_font_face_cache_load_sys arginfo_plutovg_font_face_cache_reference_count

ZEND_FUNCTION(plutovg_font_face_load_from_file);
ZEND_FUNCTION(plutovg_font_face_load_from_data);
ZEND_FUNCTION(plutovg_font_face_reference);
ZEND_FUNCTION(plutovg_font_face_destroy);
ZEND_FUNCTION(plutovg_font_face_get_reference_count);
ZEND_FUNCTION(plutovg_font_face_get_metrics);
ZEND_FUNCTION(plutovg_font_face_get_glyph_metrics);
ZEND_FUNCTION(plutovg_font_face_get_glyph_path);
ZEND_FUNCTION(plutovg_font_face_traverse_glyph_path);
ZEND_FUNCTION(plutovg_font_face_text_extents);
ZEND_FUNCTION(plutovg_font_face_cache_create);
ZEND_FUNCTION(plutovg_font_face_cache_reference);
ZEND_FUNCTION(plutovg_font_face_cache_destroy);
ZEND_FUNCTION(plutovg_font_face_cache_reference_count);
ZEND_FUNCTION(plutovg_font_face_cache_reset);
ZEND_FUNCTION(plutovg_font_face_cache_add);
ZEND_FUNCTION(plutovg_font_face_cache_add_file);
ZEND_FUNCTION(plutovg_font_face_cache_get);
ZEND_FUNCTION(plutovg_font_face_cache_load_file);
ZEND_FUNCTION(plutovg_font_face_cache_load_dir);
ZEND_FUNCTION(plutovg_font_face_cache_load_sys);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(plutovg_font_face_load_from_file, arginfo_plutovg_font_face_load_from_file)
	ZEND_FE(plutovg_font_face_load_from_data, arginfo_plutovg_font_face_load_from_data)
	ZEND_FE(plutovg_font_face_reference, arginfo_plutovg_font_face_reference)
	ZEND_FE(plutovg_font_face_destroy, arginfo_plutovg_font_face_destroy)
	ZEND_FE(plutovg_font_face_get_reference_count, arginfo_plutovg_font_face_get_reference_count)
	ZEND_FE(plutovg_font_face_get_metrics, arginfo_plutovg_font_face_get_metrics)
	ZEND_FE(plutovg_font_face_get_glyph_metrics, arginfo_plutovg_font_face_get_glyph_metrics)
	ZEND_FE(plutovg_font_face_get_glyph_path, arginfo_plutovg_font_face_get_glyph_path)
	ZEND_FE(plutovg_font_face_traverse_glyph_path, arginfo_plutovg_font_face_traverse_glyph_path)
	ZEND_FE(plutovg_font_face_text_extents, arginfo_plutovg_font_face_text_extents)
	ZEND_FE(plutovg_font_face_cache_create, arginfo_plutovg_font_face_cache_create)
	ZEND_FE(plutovg_font_face_cache_reference, arginfo_plutovg_font_face_cache_reference)
	ZEND_FE(plutovg_font_face_cache_destroy, arginfo_plutovg_font_face_cache_destroy)
	ZEND_FE(plutovg_font_face_cache_reference_count, arginfo_plutovg_font_face_cache_reference_count)
	ZEND_FE(plutovg_font_face_cache_reset, arginfo_plutovg_font_face_cache_reset)
	ZEND_FE(plutovg_font_face_cache_add, arginfo_plutovg_font_face_cache_add)
	ZEND_FE(plutovg_font_face_cache_add_file, arginfo_plutovg_font_face_cache_add_file)
	ZEND_FE(plutovg_font_face_cache_get, arginfo_plutovg_font_face_cache_get)
	ZEND_FE(plutovg_font_face_cache_load_file, arginfo_plutovg_font_face_cache_load_file)
	ZEND_FE(plutovg_font_face_cache_load_dir, arginfo_plutovg_font_face_cache_load_dir)
	ZEND_FE(plutovg_font_face_cache_load_sys, arginfo_plutovg_font_face_cache_load_sys)
	ZEND_FE_END
};
