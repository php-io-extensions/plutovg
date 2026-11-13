<?php

/** @generate-class-entries */

/** plutovg_point_t. Floats are stored as C float when they cross into PlutoVG. */
final class plutovg_point
{
    public float $x = 0.0;
    public float $y = 0.0;

    public function __construct(float $x = 0.0, float $y = 0.0) {}
}

/** plutovg_rect_t. */
final class plutovg_rect
{
    public float $x = 0.0;
    public float $y = 0.0;
    public float $w = 0.0;
    public float $h = 0.0;

    public function __construct(float $x = 0.0, float $y = 0.0, float $w = 0.0, float $h = 0.0) {}
}

/** plutovg_matrix_t. A new matrix is the zero matrix, as in C; plutovg_matrix_init_identity() makes it identity. */
final class plutovg_matrix
{
    public float $a = 0.0;
    public float $b = 0.0;
    public float $c = 0.0;
    public float $d = 0.0;
    public float $e = 0.0;
    public float $f = 0.0;

    public function __construct(float $a = 0.0, float $b = 0.0, float $c = 0.0, float $d = 0.0, float $e = 0.0, float $f = 0.0) {}
}

/** plutovg_color_t. */
final class plutovg_color
{
    public float $r = 0.0;
    public float $g = 0.0;
    public float $b = 0.0;
    public float $a = 0.0;

    public function __construct(float $r = 0.0, float $g = 0.0, float $b = 0.0, float $a = 0.0) {}
}

/** plutovg_gradient_stop_t. */
final class plutovg_gradient_stop
{
    public float $offset = 0.0;
    public ?plutovg_color $color = null;

    public function __construct(float $offset = 0.0, ?plutovg_color $color = null) {}
}

/** The header member of union plutovg_path_element_t. */
final class plutovg_path_element_header
{
    public int $command = 0;
    public int $length = 0;

    public function __construct(int $command = 0, int $length = 0) {}
}

/**
 * union plutovg_path_element_t, as plutovg_path_get_elements() returns it: exactly one of
 * $header (a command's first element) or $point (the elements after it) is set.
 */
final class plutovg_path_element
{
    public ?plutovg_path_element_header $header = null;
    public ?plutovg_point $point = null;

    public function __construct(?plutovg_path_element_header $header = null, ?plutovg_point $point = null) {}
}

/**
 * plutovg_path_t: one reference to a path. Freed when the object goes, or by plutovg_path_destroy().
 * @not-serializable
 */
final class plutovg_path
{
    private function __construct() {}
}

/**
 * plutovg_path_iterator_t. Holds the path it was initialised from; the path must not change while
 * it iterates (plutovg_path_iterator_next() throws if it did).
 * @not-serializable
 */
final class plutovg_path_iterator
{
    public function __construct() {}
}

/**
 * plutovg_text_iterator_t. Holds the string it was initialised from.
 * @not-serializable
 */
final class plutovg_text_iterator
{
    public function __construct() {}
}

/**
 * plutovg_surface_t: one reference to a surface. Freed when the object goes, or by plutovg_surface_destroy().
 * @not-serializable
 */
final class plutovg_surface
{
    private function __construct() {}
}

/**
 * plutovg_paint_t: one reference to a paint.
 * @not-serializable
 */
final class plutovg_paint
{
    private function __construct() {}
}

/**
 * plutovg_canvas_t: one reference to a canvas.
 * @not-serializable
 */
final class plutovg_canvas
{
    private function __construct() {}
}

/**
 * plutovg_font_face_t: one reference to a font face. Font data is parsed by stb_truetype, which trusts it:
 * load only fonts you trust.
 * @not-serializable
 */
final class plutovg_font_face
{
    private function __construct() {}
}

/**
 * plutovg_font_face_cache_t: one reference to a font face cache.
 * @not-serializable
 */
final class plutovg_font_face_cache
{
    private function __construct() {}
}
