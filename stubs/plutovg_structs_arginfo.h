/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8a0de7d3e4133b8875902b7a0a197e5fe0aa62a0 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_point___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_rect___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, w, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, h, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_matrix___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, a, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, b, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, c, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, d, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, e, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, f, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_color___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, r, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, g, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, b, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, a, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_gradient_stop___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, color, plutovg_color, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_path_element_header___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, command, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_path_element___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, header, plutovg_path_element_header, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, plutovg_point, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_plutovg_path___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_plutovg_path_iterator___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_text_iterator___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_surface___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_paint___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_canvas___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_font_face___construct arginfo_class_plutovg_path___construct

#define arginfo_class_plutovg_font_face_cache___construct arginfo_class_plutovg_path___construct

ZEND_METHOD(plutovg_point, __construct);
ZEND_METHOD(plutovg_rect, __construct);
ZEND_METHOD(plutovg_matrix, __construct);
ZEND_METHOD(plutovg_color, __construct);
ZEND_METHOD(plutovg_gradient_stop, __construct);
ZEND_METHOD(plutovg_path_element_header, __construct);
ZEND_METHOD(plutovg_path_element, __construct);
ZEND_METHOD(plutovg_path, __construct);
ZEND_METHOD(plutovg_path_iterator, __construct);
ZEND_METHOD(plutovg_text_iterator, __construct);
ZEND_METHOD(plutovg_surface, __construct);
ZEND_METHOD(plutovg_paint, __construct);
ZEND_METHOD(plutovg_canvas, __construct);
ZEND_METHOD(plutovg_font_face, __construct);
ZEND_METHOD(plutovg_font_face_cache, __construct);

static const zend_function_entry class_plutovg_point_methods[] = {
	ZEND_ME(plutovg_point, __construct, arginfo_class_plutovg_point___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_rect_methods[] = {
	ZEND_ME(plutovg_rect, __construct, arginfo_class_plutovg_rect___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_matrix_methods[] = {
	ZEND_ME(plutovg_matrix, __construct, arginfo_class_plutovg_matrix___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_color_methods[] = {
	ZEND_ME(plutovg_color, __construct, arginfo_class_plutovg_color___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_gradient_stop_methods[] = {
	ZEND_ME(plutovg_gradient_stop, __construct, arginfo_class_plutovg_gradient_stop___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_path_element_header_methods[] = {
	ZEND_ME(plutovg_path_element_header, __construct, arginfo_class_plutovg_path_element_header___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_path_element_methods[] = {
	ZEND_ME(plutovg_path_element, __construct, arginfo_class_plutovg_path_element___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_path_methods[] = {
	ZEND_ME(plutovg_path, __construct, arginfo_class_plutovg_path___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_path_iterator_methods[] = {
	ZEND_ME(plutovg_path_iterator, __construct, arginfo_class_plutovg_path_iterator___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_text_iterator_methods[] = {
	ZEND_ME(plutovg_text_iterator, __construct, arginfo_class_plutovg_text_iterator___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_surface_methods[] = {
	ZEND_ME(plutovg_surface, __construct, arginfo_class_plutovg_surface___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_paint_methods[] = {
	ZEND_ME(plutovg_paint, __construct, arginfo_class_plutovg_paint___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_canvas_methods[] = {
	ZEND_ME(plutovg_canvas, __construct, arginfo_class_plutovg_canvas___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_font_face_methods[] = {
	ZEND_ME(plutovg_font_face, __construct, arginfo_class_plutovg_font_face___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_plutovg_font_face_cache_methods[] = {
	ZEND_ME(plutovg_font_face_cache, __construct, arginfo_class_plutovg_font_face_cache___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static zend_class_entry *register_class_plutovg_point(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_point", class_plutovg_point_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0.0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0.0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_rect(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_rect", class_plutovg_rect_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0.0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0.0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	zval property_w_default_value;
	ZVAL_DOUBLE(&property_w_default_value, 0.0);
	zend_string *property_w_name = zend_string_init("w", sizeof("w") - 1, 1);
	zend_declare_typed_property(class_entry, property_w_name, &property_w_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_w_name);

	zval property_h_default_value;
	ZVAL_DOUBLE(&property_h_default_value, 0.0);
	zend_string *property_h_name = zend_string_init("h", sizeof("h") - 1, 1);
	zend_declare_typed_property(class_entry, property_h_name, &property_h_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_h_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_matrix(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_matrix", class_plutovg_matrix_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_a_default_value;
	ZVAL_DOUBLE(&property_a_default_value, 0.0);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_a_name);

	zval property_b_default_value;
	ZVAL_DOUBLE(&property_b_default_value, 0.0);
	zend_string *property_b_name = zend_string_init("b", sizeof("b") - 1, 1);
	zend_declare_typed_property(class_entry, property_b_name, &property_b_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_b_name);

	zval property_c_default_value;
	ZVAL_DOUBLE(&property_c_default_value, 0.0);
	zend_string *property_c_name = zend_string_init("c", sizeof("c") - 1, 1);
	zend_declare_typed_property(class_entry, property_c_name, &property_c_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_c_name);

	zval property_d_default_value;
	ZVAL_DOUBLE(&property_d_default_value, 0.0);
	zend_string *property_d_name = zend_string_init("d", sizeof("d") - 1, 1);
	zend_declare_typed_property(class_entry, property_d_name, &property_d_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_d_name);

	zval property_e_default_value;
	ZVAL_DOUBLE(&property_e_default_value, 0.0);
	zend_string *property_e_name = zend_string_init("e", sizeof("e") - 1, 1);
	zend_declare_typed_property(class_entry, property_e_name, &property_e_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_e_name);

	zval property_f_default_value;
	ZVAL_DOUBLE(&property_f_default_value, 0.0);
	zend_string *property_f_name = zend_string_init("f", sizeof("f") - 1, 1);
	zend_declare_typed_property(class_entry, property_f_name, &property_f_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_f_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_color(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_color", class_plutovg_color_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_r_default_value;
	ZVAL_DOUBLE(&property_r_default_value, 0.0);
	zend_string *property_r_name = zend_string_init("r", sizeof("r") - 1, 1);
	zend_declare_typed_property(class_entry, property_r_name, &property_r_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_r_name);

	zval property_g_default_value;
	ZVAL_DOUBLE(&property_g_default_value, 0.0);
	zend_string *property_g_name = zend_string_init("g", sizeof("g") - 1, 1);
	zend_declare_typed_property(class_entry, property_g_name, &property_g_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_g_name);

	zval property_b_default_value;
	ZVAL_DOUBLE(&property_b_default_value, 0.0);
	zend_string *property_b_name = zend_string_init("b", sizeof("b") - 1, 1);
	zend_declare_typed_property(class_entry, property_b_name, &property_b_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_b_name);

	zval property_a_default_value;
	ZVAL_DOUBLE(&property_a_default_value, 0.0);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_a_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_gradient_stop(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_gradient_stop", class_plutovg_gradient_stop_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_offset_default_value;
	ZVAL_DOUBLE(&property_offset_default_value, 0.0);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_offset_name);

	zval property_color_default_value;
	ZVAL_NULL(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, 1);
	zend_string *property_color_class_plutovg_color = zend_string_init("plutovg_color", sizeof("plutovg_color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_plutovg_color, 0, MAY_BE_NULL));
	zend_string_release(property_color_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_path_element_header(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_path_element_header", class_plutovg_path_element_header_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_command_default_value;
	ZVAL_LONG(&property_command_default_value, 0);
	zend_string *property_command_name = zend_string_init("command", sizeof("command") - 1, 1);
	zend_declare_typed_property(class_entry, property_command_name, &property_command_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_command_name);

	zval property_length_default_value;
	ZVAL_LONG(&property_length_default_value, 0);
	zend_string *property_length_name = zend_string_init("length", sizeof("length") - 1, 1);
	zend_declare_typed_property(class_entry, property_length_name, &property_length_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_length_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_path_element(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_path_element", class_plutovg_path_element_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_header_default_value;
	ZVAL_NULL(&property_header_default_value);
	zend_string *property_header_name = zend_string_init("header", sizeof("header") - 1, 1);
	zend_string *property_header_class_plutovg_path_element_header = zend_string_init("plutovg_path_element_header", sizeof("plutovg_path_element_header")-1, 1);
	zend_declare_typed_property(class_entry, property_header_name, &property_header_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_header_class_plutovg_path_element_header, 0, MAY_BE_NULL));
	zend_string_release(property_header_name);

	zval property_point_default_value;
	ZVAL_NULL(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_plutovg_point = zend_string_init("plutovg_point", sizeof("plutovg_point")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_plutovg_point, 0, MAY_BE_NULL));
	zend_string_release(property_point_name);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_path(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_path", class_plutovg_path_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_path_iterator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_path_iterator", class_plutovg_path_iterator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_text_iterator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_text_iterator", class_plutovg_text_iterator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_surface(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_surface", class_plutovg_surface_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_paint(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_paint", class_plutovg_paint_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_canvas(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_canvas", class_plutovg_canvas_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_font_face(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_font_face", class_plutovg_font_face_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_plutovg_font_face_cache(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "plutovg_font_face_cache", class_plutovg_font_face_cache_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
