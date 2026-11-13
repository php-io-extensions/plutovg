<?php

/** @generate-class-entries */

function plutovg_canvas_create(plutovg_surface $surface): plutovg_canvas {}

function plutovg_canvas_reference(plutovg_canvas $canvas): plutovg_canvas {}

function plutovg_canvas_destroy(plutovg_canvas $canvas): void {}

function plutovg_canvas_get_reference_count(plutovg_canvas $canvas): int {}

function plutovg_canvas_get_surface(plutovg_canvas $canvas): plutovg_surface {}

function plutovg_canvas_save(plutovg_canvas $canvas): void {}

function plutovg_canvas_restore(plutovg_canvas $canvas): void {}

function plutovg_canvas_set_rgb(plutovg_canvas $canvas, float $r, float $g, float $b): void {}

function plutovg_canvas_set_rgba(plutovg_canvas $canvas, float $r, float $g, float $b, float $a): void {}

function plutovg_canvas_set_color(plutovg_canvas $canvas, plutovg_color $color): void {}

function plutovg_canvas_set_linear_gradient(plutovg_canvas $canvas, float $x1, float $y1, float $x2, float $y2, int $spread, array $stops, int $nstops, ?plutovg_matrix $matrix): void {}

function plutovg_canvas_set_radial_gradient(plutovg_canvas $canvas, float $cx, float $cy, float $cr, float $fx, float $fy, float $fr, int $spread, array $stops, int $nstops, ?plutovg_matrix $matrix): void {}

function plutovg_canvas_set_texture(plutovg_canvas $canvas, plutovg_surface $surface, int $type, float $opacity, ?plutovg_matrix $matrix): void {}

function plutovg_canvas_set_paint(plutovg_canvas $canvas, ?plutovg_paint $paint): void {}

function plutovg_canvas_get_paint(plutovg_canvas $canvas, ?plutovg_color $color): ?plutovg_paint {}

function plutovg_canvas_set_font_face_cache(plutovg_canvas $canvas, ?plutovg_font_face_cache $cache): void {}

function plutovg_canvas_get_font_face_cache(plutovg_canvas $canvas): ?plutovg_font_face_cache {}

function plutovg_canvas_add_font_face(plutovg_canvas $canvas, string $family, bool $bold, bool $italic, ?plutovg_font_face $face): void {}

function plutovg_canvas_add_font_file(plutovg_canvas $canvas, string $family, bool $bold, bool $italic, string $filename, int $ttcindex): bool {}

function plutovg_canvas_select_font_face(plutovg_canvas $canvas, string $family, bool $bold, bool $italic): bool {}

function plutovg_canvas_set_font(plutovg_canvas $canvas, ?plutovg_font_face $face, float $size): void {}

function plutovg_canvas_set_font_face(plutovg_canvas $canvas, ?plutovg_font_face $face): void {}

function plutovg_canvas_get_font_face(plutovg_canvas $canvas): ?plutovg_font_face {}

function plutovg_canvas_set_font_size(plutovg_canvas $canvas, float $size): void {}

function plutovg_canvas_get_font_size(plutovg_canvas $canvas): float {}

function plutovg_canvas_set_fill_rule(plutovg_canvas $canvas, int $winding): void {}

function plutovg_canvas_get_fill_rule(plutovg_canvas $canvas): int {}

function plutovg_canvas_set_operator(plutovg_canvas $canvas, int $op): void {}

function plutovg_canvas_get_operator(plutovg_canvas $canvas): int {}

function plutovg_canvas_set_opacity(plutovg_canvas $canvas, float $opacity): void {}

function plutovg_canvas_get_opacity(plutovg_canvas $canvas): float {}

function plutovg_canvas_set_line_width(plutovg_canvas $canvas, float $line_width): void {}

function plutovg_canvas_get_line_width(plutovg_canvas $canvas): float {}

function plutovg_canvas_set_line_cap(plutovg_canvas $canvas, int $line_cap): void {}

function plutovg_canvas_get_line_cap(plutovg_canvas $canvas): int {}

function plutovg_canvas_set_line_join(plutovg_canvas $canvas, int $line_join): void {}

function plutovg_canvas_get_line_join(plutovg_canvas $canvas): int {}

function plutovg_canvas_set_miter_limit(plutovg_canvas $canvas, float $miter_limit): void {}

function plutovg_canvas_get_miter_limit(plutovg_canvas $canvas): float {}

function plutovg_canvas_set_dash(plutovg_canvas $canvas, float $offset, array $dashes, int $ndashes): void {}

function plutovg_canvas_set_dash_offset(plutovg_canvas $canvas, float $offset): void {}

function plutovg_canvas_get_dash_offset(plutovg_canvas $canvas): float {}

function plutovg_canvas_set_dash_array(plutovg_canvas $canvas, array $dashes, int $ndashes): void {}

function plutovg_canvas_get_dash_array(plutovg_canvas $canvas, ?array &$dashes): int {}

function plutovg_canvas_translate(plutovg_canvas $canvas, float $tx, float $ty): void {}

function plutovg_canvas_scale(plutovg_canvas $canvas, float $sx, float $sy): void {}

function plutovg_canvas_shear(plutovg_canvas $canvas, float $shx, float $shy): void {}

function plutovg_canvas_rotate(plutovg_canvas $canvas, float $angle): void {}

function plutovg_canvas_transform(plutovg_canvas $canvas, plutovg_matrix $matrix): void {}

function plutovg_canvas_reset_matrix(plutovg_canvas $canvas): void {}

function plutovg_canvas_set_matrix(plutovg_canvas $canvas, plutovg_matrix $matrix): void {}

function plutovg_canvas_get_matrix(plutovg_canvas $canvas, plutovg_matrix $matrix): void {}

function plutovg_canvas_map(plutovg_canvas $canvas, float $x, float $y, ?float &$xx, ?float &$yy): void {}

function plutovg_canvas_map_point(plutovg_canvas $canvas, plutovg_point $src, plutovg_point $dst): void {}

function plutovg_canvas_map_rect(plutovg_canvas $canvas, plutovg_rect $src, plutovg_rect $dst): void {}

function plutovg_canvas_move_to(plutovg_canvas $canvas, float $x, float $y): void {}

function plutovg_canvas_line_to(plutovg_canvas $canvas, float $x, float $y): void {}

function plutovg_canvas_quad_to(plutovg_canvas $canvas, float $x1, float $y1, float $x2, float $y2): void {}

function plutovg_canvas_cubic_to(plutovg_canvas $canvas, float $x1, float $y1, float $x2, float $y2, float $x3, float $y3): void {}

function plutovg_canvas_arc_to(plutovg_canvas $canvas, float $rx, float $ry, float $angle, bool $large_arc_flag, bool $sweep_flag, float $x, float $y): void {}

function plutovg_canvas_rect(plutovg_canvas $canvas, float $x, float $y, float $w, float $h): void {}

function plutovg_canvas_round_rect(plutovg_canvas $canvas, float $x, float $y, float $w, float $h, float $rx, float $ry): void {}

function plutovg_canvas_ellipse(plutovg_canvas $canvas, float $cx, float $cy, float $rx, float $ry): void {}

function plutovg_canvas_circle(plutovg_canvas $canvas, float $cx, float $cy, float $r): void {}

function plutovg_canvas_arc(plutovg_canvas $canvas, float $cx, float $cy, float $r, float $a0, float $a1, bool $ccw): void {}

function plutovg_canvas_add_path(plutovg_canvas $canvas, plutovg_path $path): void {}

function plutovg_canvas_new_path(plutovg_canvas $canvas): void {}

function plutovg_canvas_close_path(plutovg_canvas $canvas): void {}

function plutovg_canvas_get_current_point(plutovg_canvas $canvas, ?float &$x, ?float &$y): void {}

function plutovg_canvas_get_path(plutovg_canvas $canvas): plutovg_path {}

function plutovg_canvas_fill_contains(plutovg_canvas $canvas, float $x, float $y): bool {}

function plutovg_canvas_stroke_contains(plutovg_canvas $canvas, float $x, float $y): bool {}

function plutovg_canvas_clip_contains(plutovg_canvas $canvas, float $x, float $y): bool {}

function plutovg_canvas_fill_extents(plutovg_canvas $canvas, plutovg_rect $extents): void {}

function plutovg_canvas_stroke_extents(plutovg_canvas $canvas, plutovg_rect $extents): void {}

function plutovg_canvas_clip_extents(plutovg_canvas $canvas, plutovg_rect $extents): void {}

function plutovg_canvas_fill(plutovg_canvas $canvas): void {}

function plutovg_canvas_stroke(plutovg_canvas $canvas): void {}

function plutovg_canvas_clip(plutovg_canvas $canvas): void {}

function plutovg_canvas_paint(plutovg_canvas $canvas): void {}

function plutovg_canvas_fill_preserve(plutovg_canvas $canvas): void {}

function plutovg_canvas_stroke_preserve(plutovg_canvas $canvas): void {}

function plutovg_canvas_clip_preserve(plutovg_canvas $canvas): void {}

function plutovg_canvas_fill_rect(plutovg_canvas $canvas, float $x, float $y, float $w, float $h): void {}

function plutovg_canvas_fill_path(plutovg_canvas $canvas, plutovg_path $path): void {}

function plutovg_canvas_stroke_rect(plutovg_canvas $canvas, float $x, float $y, float $w, float $h): void {}

function plutovg_canvas_stroke_path(plutovg_canvas $canvas, plutovg_path $path): void {}

function plutovg_canvas_clip_rect(plutovg_canvas $canvas, float $x, float $y, float $w, float $h): void {}

function plutovg_canvas_clip_path(plutovg_canvas $canvas, plutovg_path $path): void {}

function plutovg_canvas_add_glyph(plutovg_canvas $canvas, int $codepoint, float $x, float $y): float {}

function plutovg_canvas_add_text(plutovg_canvas $canvas, string $text, int $length, int $encoding, float $x, float $y): float {}

function plutovg_canvas_fill_text(plutovg_canvas $canvas, string $text, int $length, int $encoding, float $x, float $y): float {}

function plutovg_canvas_stroke_text(plutovg_canvas $canvas, string $text, int $length, int $encoding, float $x, float $y): float {}

function plutovg_canvas_clip_text(plutovg_canvas $canvas, string $text, int $length, int $encoding, float $x, float $y): float {}

function plutovg_canvas_font_metrics(plutovg_canvas $canvas, ?float &$ascent, ?float &$descent, ?float &$line_gap, ?plutovg_rect $extents): void {}

function plutovg_canvas_glyph_metrics(plutovg_canvas $canvas, int $codepoint, ?float &$advance_width, ?float &$left_side_bearing, ?plutovg_rect $extents): void {}

function plutovg_canvas_text_extents(plutovg_canvas $canvas, string $text, int $length, int $encoding, ?plutovg_rect $extents): float {}
