<?php

/** @generate-class-entries */

function plutovg_color_init_rgb(plutovg_color $color, float $r, float $g, float $b): void {}

function plutovg_color_init_rgba(plutovg_color $color, float $r, float $g, float $b, float $a): void {}

function plutovg_color_init_rgb8(plutovg_color $color, int $r, int $g, int $b): void {}

function plutovg_color_init_rgba8(plutovg_color $color, int $r, int $g, int $b, int $a): void {}

function plutovg_color_init_rgba32(plutovg_color $color, int $value): void {}

function plutovg_color_init_argb32(plutovg_color $color, int $value): void {}

function plutovg_color_init_hsl(plutovg_color $color, float $h, float $s, float $l): void {}

function plutovg_color_init_hsla(plutovg_color $color, float $h, float $s, float $l, float $a): void {}

function plutovg_color_to_rgba32(plutovg_color $color): int {}

function plutovg_color_to_argb32(plutovg_color $color): int {}

/** $length: bytes of $data, or -1 for all of it. Returns the bytes consumed (0: not a colour). */
function plutovg_color_parse(plutovg_color $color, string $data, int $length): int {}

function plutovg_surface_create(int $width, int $height): ?plutovg_surface {}

/**
 * The surface draws into $data itself: the binding keeps that string (and every handle built on the
 * surface keeps it too), so changes show in plutovg_surface_get_data(), not in the caller's variable.
 */
function plutovg_surface_create_for_data(string $data, int $width, int $height, int $stride): ?plutovg_surface {}

/**
 * Binding addition: a surface over memory another extension owns (for example a pixman image's bits,
 * from pixman_image_get_data_address()). $owner is kept alive as long as the surface or anything built on it.
 * The caller vouches that $address holds $stride * $height writable bytes for that long.
 */
function plutovg_surface_create_for_address(int $address, int $width, int $height, int $stride, object $owner): ?plutovg_surface {}

function plutovg_surface_load_from_image_file(string $filename): ?plutovg_surface {}

/** $length: bytes of $data, or -1 for all of it. */
function plutovg_surface_load_from_image_data(string $data, int $length): ?plutovg_surface {}

/** $length: bytes of $data, or -1 for all of it. */
function plutovg_surface_load_from_image_base64(string $data, int $length): ?plutovg_surface {}

function plutovg_surface_reference(plutovg_surface $surface): plutovg_surface {}

function plutovg_surface_destroy(plutovg_surface $surface): void {}

function plutovg_surface_get_reference_count(plutovg_surface $surface): int {}

/** A copy of the pixels: stride * height bytes of premultiplied ARGB32 in native byte order. */
function plutovg_surface_get_data(plutovg_surface $surface): string {}

/** Binding addition: the address of the surface's pixels. */
function plutovg_surface_get_data_address(plutovg_surface $surface): int {}

/**
 * Binding addition: the alpha byte of every pixel, width * height bytes, rows packed (no stride
 * padding), top row first. For a surface filled in opaque white this is the fill's a8 coverage.
 */
function plutovg_surface_get_alpha(plutovg_surface $surface): string {}

/**
 * Binding addition: blends $rgba (0xRRGGBBAA, straight) into straight 32-bit memory through the
 * alpha of $coverage, placed with its top-left at ($x, $y) in the memory. Per pixel, with c the
 * coverage: a = (alpha * c + 127) / 255; nothing at a = 0, the colour itself (opaque) at a = 255,
 * else each byte (colour * a + pixel * (255 - a) + 127) / 255, alpha (255 * a + pixelAlpha *
 * (255 - a) + 127) / 255: VelvetGE's arithmetic. Pixels outside the memory are skipped.
 *
 * $address is trusted to hold $height rows of $stride bytes for as long as the call runs.
 * Returns [x, y, width, height] around the memory pixels with coverage, or null when none had.
 *
 * @return array{int, int, int, int}|null
 */
function plutovg_surface_blend_colour(plutovg_surface $coverage, int $address, int $width, int $height, int $stride, int $order, int $x, int $y, int $rgba): ?array {}

/**
 * Binding addition: as plutovg_surface_blend_colour(), the colour of each pixel sampled from a
 * 256-colour RGBA8 $ramp (1024 bytes). The pixel centre (px + 0.5, py + 0.5) maps through
 * $inverse [a, b, c, d, e, f] to u = a·x + c·y + e, v = b·x + d·y + f; t is u, or hypot(u, v) when
 * $radial; $spread (PLUTOVG_SPREAD_METHOD_*) folds t into 0..1; the entry is round(t · 255). Its
 * alpha times the coverage is the a above.
 *
 * @return array{int, int, int, int}|null
 */
function plutovg_surface_blend_ramp(plutovg_surface $coverage, int $address, int $width, int $height, int $stride, int $order, int $x, int $y, string $ramp, bool $radial, int $spread, array $inverse): ?array {}

function plutovg_surface_get_width(plutovg_surface $surface): int {}

function plutovg_surface_get_height(plutovg_surface $surface): int {}

function plutovg_surface_get_stride(plutovg_surface $surface): int {}

function plutovg_surface_clear(plutovg_surface $surface, plutovg_color $color): void {}

function plutovg_surface_write_to_png(plutovg_surface $surface, string $filename): bool {}

function plutovg_surface_write_to_jpg(plutovg_surface $surface, string $filename, int $quality): bool {}

/** $write_func(string $data, int $size). */
function plutovg_surface_write_to_png_stream(plutovg_surface $surface, callable $write_func): bool {}

function plutovg_surface_write_to_jpg_stream(plutovg_surface $surface, callable $write_func, int $quality): bool {}

/** $dst becomes the converted copy of $src (same length). */
function plutovg_convert_argb_to_rgba(?string &$dst, string $src, int $width, int $height, int $stride): void {}

function plutovg_convert_rgba_to_argb(?string &$dst, string $src, int $width, int $height, int $stride): void {}

function plutovg_paint_create_rgb(float $r, float $g, float $b): plutovg_paint {}

function plutovg_paint_create_rgba(float $r, float $g, float $b, float $a): plutovg_paint {}

function plutovg_paint_create_color(plutovg_color $color): plutovg_paint {}

/** $stops: a list of plutovg_gradient_stop. */
function plutovg_paint_create_linear_gradient(float $x1, float $y1, float $x2, float $y2, int $spread, array $stops, int $nstops, ?plutovg_matrix $matrix): plutovg_paint {}

/** $stops: a list of plutovg_gradient_stop. */
function plutovg_paint_create_radial_gradient(float $cx, float $cy, float $cr, float $fx, float $fy, float $fr, int $spread, array $stops, int $nstops, ?plutovg_matrix $matrix): plutovg_paint {}

function plutovg_paint_create_texture(plutovg_surface $surface, int $type, float $opacity, ?plutovg_matrix $matrix): plutovg_paint {}

function plutovg_paint_reference(plutovg_paint $paint): plutovg_paint {}

function plutovg_paint_destroy(plutovg_paint $paint): void {}

function plutovg_paint_get_reference_count(plutovg_paint $paint): int {}
