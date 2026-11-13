<?php

declare(strict_types=1);

beforeEach(function (): void {
    if (pv_font_file() === null) {
        $this->markTestSkipped('no TrueType font found on this machine');
    }
});

it('loads a face from a file and from data, with metrics', function (): void {
    $file = pv_font_file();
    $face = plutovg_font_face_load_from_file($file, 0);
    $copy = plutovg_font_face_load_from_data(file_get_contents($file), filesize($file), 0);

    plutovg_font_face_get_metrics($face, 20, $ascent, $descent, $gap, null);
    plutovg_font_face_get_glyph_metrics($copy, 20, ord('A'), $advance, $bearing, $box = new plutovg_rect());
    expect($ascent)->toBeGreaterThan(0)
        ->and($descent)->toBeLessThan(0)
        ->and($advance)->toBeGreaterThan(5)
        ->and($box->h)->toBeGreaterThan(5)
        ->and(plutovg_font_face_load_from_data(str_repeat('x', 64), 64, 0))->toBeNull()
        ->and(fn () => plutovg_font_face_load_from_data('tiny', 4, 0))->toThrow(ValueError::class);
});

it('builds and walks glyph paths and measures text', function (): void {
    $face = plutovg_font_face_load_from_file(pv_font_file(), 0);
    $path = plutovg_path_create();
    $advance = plutovg_font_face_get_glyph_path($face, 20, 0, 20, ord('O'), $path);
    $calls = 0;
    plutovg_font_face_traverse_glyph_path($face, 20, 0, 20, ord('O'), function () use (&$calls): void { $calls++; });

    $extents = new plutovg_rect();
    expect($advance)->toBeGreaterThan(5)
        ->and(plutovg_path_length($path))->toBeGreaterThan(20)
        ->and($calls)->toBeGreaterThan(4)
        ->and(plutovg_font_face_text_extents($face, 20, 'Hi', -1, PLUTOVG_TEXT_ENCODING_UTF8, $extents))->toBeGreaterThan($advance / 2)
        ->and(fn () => plutovg_font_face_get_glyph_path($face, 20, 0, 0, -1, $path))->toThrow(ValueError::class);
});

it('finds faces through a cache and draws text on a canvas', function (): void {
    $cache = plutovg_font_face_cache_create();
    $family = 'Test Sans';
    expect(plutovg_font_face_cache_add_file($cache, $family, false, false, pv_font_file(), 0))->toBeTrue();
    $face = plutovg_font_face_cache_get($cache, $family, false, false);
    expect($face)->toBeInstanceOf(plutovg_font_face::class)
        ->and(plutovg_font_face_cache_get($cache, 'nope', false, false))->toBeNull();

    $s = plutovg_surface_create(40, 20);
    $c = plutovg_canvas_create($s);
    plutovg_canvas_set_font_face_cache($c, $cache);
    expect(plutovg_canvas_select_font_face($c, $family, false, false))->toBeTrue();
    plutovg_canvas_set_font_size($c, 16);
    plutovg_canvas_set_rgb($c, 1, 1, 1);
    expect(plutovg_canvas_fill_text($c, 'Hi', -1, PLUTOVG_TEXT_ENCODING_UTF8, 2, 16))->toBeGreaterThan(5)
        ->and(array_filter(pv_pixels($s)))->not->toBeEmpty();
});
