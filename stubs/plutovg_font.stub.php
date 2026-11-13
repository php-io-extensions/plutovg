<?php

/** @generate-class-entries */

function plutovg_font_face_load_from_file(string $filename, int $ttcindex): ?plutovg_font_face {}

/** The face keeps its own copy of $data (the C destroy_func/closure pair is the binding's). */
function plutovg_font_face_load_from_data(string $data, int $length, int $ttcindex): ?plutovg_font_face {}

function plutovg_font_face_reference(plutovg_font_face $face): plutovg_font_face {}

function plutovg_font_face_destroy(plutovg_font_face $face): void {}

function plutovg_font_face_get_reference_count(plutovg_font_face $face): int {}

function plutovg_font_face_get_metrics(plutovg_font_face $face, float $size, ?float &$ascent, ?float &$descent, ?float &$line_gap, ?plutovg_rect $extents): void {}

function plutovg_font_face_get_glyph_metrics(plutovg_font_face $face, float $size, int $codepoint, ?float &$advance_width, ?float &$left_side_bearing, ?plutovg_rect $extents): void {}

function plutovg_font_face_get_glyph_path(plutovg_font_face $face, float $size, float $x, float $y, int $codepoint, plutovg_path $path): float {}

/** $traverse_func(int $command, array $points, int $npoints). */
function plutovg_font_face_traverse_glyph_path(plutovg_font_face $face, float $size, float $x, float $y, int $codepoint, callable $traverse_func): float {}

function plutovg_font_face_text_extents(plutovg_font_face $face, float $size, string $text, int $length, int $encoding, ?plutovg_rect $extents): float {}

function plutovg_font_face_cache_create(): plutovg_font_face_cache {}

function plutovg_font_face_cache_reference(plutovg_font_face_cache $cache): plutovg_font_face_cache {}

function plutovg_font_face_cache_destroy(plutovg_font_face_cache $cache): void {}

function plutovg_font_face_cache_reference_count(plutovg_font_face_cache $cache): int {}

function plutovg_font_face_cache_reset(plutovg_font_face_cache $cache): void {}

function plutovg_font_face_cache_add(plutovg_font_face_cache $cache, string $family, bool $bold, bool $italic, ?plutovg_font_face $face): void {}

function plutovg_font_face_cache_add_file(plutovg_font_face_cache $cache, string $family, bool $bold, bool $italic, string $filename, int $ttcindex): bool {}

function plutovg_font_face_cache_get(plutovg_font_face_cache $cache, string $family, bool $bold, bool $italic): ?plutovg_font_face {}

function plutovg_font_face_cache_load_file(plutovg_font_face_cache $cache, string $filename): int {}

function plutovg_font_face_cache_load_dir(plutovg_font_face_cache $cache, string $dirname): int {}

/** Scans the system font directories; refused while open_basedir is set. */
function plutovg_font_face_cache_load_sys(plutovg_font_face_cache $cache): int {}
