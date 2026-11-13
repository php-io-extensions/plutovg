<?php

/** @generate-class-entries */

function plutovg_matrix_init(plutovg_matrix $matrix, float $a, float $b, float $c, float $d, float $e, float $f): void {}

function plutovg_matrix_init_identity(plutovg_matrix $matrix): void {}

function plutovg_matrix_init_translate(plutovg_matrix $matrix, float $tx, float $ty): void {}

function plutovg_matrix_init_scale(plutovg_matrix $matrix, float $sx, float $sy): void {}

function plutovg_matrix_init_rotate(plutovg_matrix $matrix, float $angle): void {}

function plutovg_matrix_init_shear(plutovg_matrix $matrix, float $shx, float $shy): void {}

function plutovg_matrix_translate(plutovg_matrix $matrix, float $tx, float $ty): void {}

function plutovg_matrix_scale(plutovg_matrix $matrix, float $sx, float $sy): void {}

function plutovg_matrix_rotate(plutovg_matrix $matrix, float $angle): void {}

function plutovg_matrix_shear(plutovg_matrix $matrix, float $shx, float $shy): void {}

function plutovg_matrix_multiply(plutovg_matrix $matrix, plutovg_matrix $left, plutovg_matrix $right): void {}

function plutovg_matrix_invert(plutovg_matrix $matrix, ?plutovg_matrix $inverse): bool {}

function plutovg_matrix_map(plutovg_matrix $matrix, float $x, float $y, ?float &$xx, ?float &$yy): void {}

function plutovg_matrix_map_point(plutovg_matrix $matrix, plutovg_point $src, plutovg_point $dst): void {}

/**
 * $src: a list of plutovg_point.
 * $dst becomes a list of $count new points.
 */
function plutovg_matrix_map_points(plutovg_matrix $matrix, array $src, ?array &$dst, int $count): void {}

function plutovg_matrix_map_rect(plutovg_matrix $matrix, plutovg_rect $src, plutovg_rect $dst): void {}

/** $length: bytes of $data to parse, or -1 for all of it. */
function plutovg_matrix_parse(plutovg_matrix $matrix, string $data, int $length): bool {}

function plutovg_path_iterator_init(plutovg_path_iterator $it, plutovg_path $path): void {}

function plutovg_path_iterator_has_next(plutovg_path_iterator $it): bool {}

/** $points becomes a list of 3 points (unused ones are zero), as the C array. */
function plutovg_path_iterator_next(plutovg_path_iterator $it, ?array &$points): int {}

function plutovg_path_create(): plutovg_path {}

function plutovg_path_reference(plutovg_path $path): plutovg_path {}

function plutovg_path_destroy(plutovg_path $path): void {}

function plutovg_path_get_reference_count(plutovg_path $path): int {}

/** $elements becomes a list of plutovg_path_element. */
function plutovg_path_get_elements(plutovg_path $path, ?array &$elements): int {}

function plutovg_path_move_to(plutovg_path $path, float $x, float $y): void {}

function plutovg_path_line_to(plutovg_path $path, float $x, float $y): void {}

function plutovg_path_quad_to(plutovg_path $path, float $x1, float $y1, float $x2, float $y2): void {}

function plutovg_path_cubic_to(plutovg_path $path, float $x1, float $y1, float $x2, float $y2, float $x3, float $y3): void {}

function plutovg_path_arc_to(plutovg_path $path, float $rx, float $ry, float $angle, bool $large_arc_flag, bool $sweep_flag, float $x, float $y): void {}

function plutovg_path_close(plutovg_path $path): void {}

function plutovg_path_get_current_point(plutovg_path $path, ?float &$x, ?float &$y): void {}

function plutovg_path_reserve(plutovg_path $path, int $count): void {}

function plutovg_path_reset(plutovg_path $path): void {}

function plutovg_path_add_rect(plutovg_path $path, float $x, float $y, float $w, float $h): void {}

function plutovg_path_add_round_rect(plutovg_path $path, float $x, float $y, float $w, float $h, float $rx, float $ry): void {}

function plutovg_path_add_ellipse(plutovg_path $path, float $cx, float $cy, float $rx, float $ry): void {}

function plutovg_path_add_circle(plutovg_path $path, float $cx, float $cy, float $r): void {}

function plutovg_path_add_arc(plutovg_path $path, float $cx, float $cy, float $r, float $a0, float $a1, bool $ccw): void {}

function plutovg_path_add_path(plutovg_path $path, plutovg_path $source, ?plutovg_matrix $matrix): void {}

function plutovg_path_transform(plutovg_path $path, plutovg_matrix $matrix): void {}

/** $traverse_func(int $command, array $points, int $npoints) with $points a list of plutovg_point. */
function plutovg_path_traverse(plutovg_path $path, callable $traverse_func): void {}

function plutovg_path_traverse_flatten(plutovg_path $path, callable $traverse_func): void {}

/** $dashes: a list of floats. */
function plutovg_path_traverse_dashed(plutovg_path $path, float $offset, array $dashes, int $ndashes, callable $traverse_func): void {}

function plutovg_path_clone(plutovg_path $path): plutovg_path {}

function plutovg_path_clone_flatten(plutovg_path $path): plutovg_path {}

/** $dashes: a list of floats. */
function plutovg_path_clone_dashed(plutovg_path $path, float $offset, array $dashes, int $ndashes): plutovg_path {}

function plutovg_path_extents(plutovg_path $path, ?plutovg_rect $extents, bool $tight): float {}

function plutovg_path_length(plutovg_path $path): float {}

/** $length: bytes of $data to parse, or -1 for all of it. */
function plutovg_path_parse(plutovg_path $path, string $data, int $length): bool {}

/** $length counts encoding units (bytes, UTF-16 or UTF-32 units), or -1 for up to the first zero unit. */
function plutovg_text_iterator_init(plutovg_text_iterator $it, string $text, int $length, int $encoding): void {}

function plutovg_text_iterator_has_next(plutovg_text_iterator $it): bool {}

function plutovg_text_iterator_next(plutovg_text_iterator $it): int {}
