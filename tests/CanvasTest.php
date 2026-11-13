<?php

declare(strict_types=1);

function pv_canvas(int $w = 10, int $h = 10): array
{
    $s = plutovg_surface_create($w, $h);

    return [$s, plutovg_canvas_create($s)];
}

it('fills a rect with exact pixels', function (): void {
    [$s, $c] = pv_canvas(4, 1);
    plutovg_canvas_set_rgb($c, 1, 0, 0);
    plutovg_canvas_fill_rect($c, 0, 0, 2, 1);

    expect(pv_pixels($s))->toBe([0xFFFF0000, 0xFFFF0000, 0, 0]);
});

it('anti-aliases a half-covered pixel and premultiplies', function (): void {
    [$s, $c] = pv_canvas(2, 1);
    plutovg_canvas_set_rgb($c, 1, 1, 1);
    plutovg_canvas_fill_rect($c, 0, 0, 1.5, 1);

    $half = pv_pixels($s)[1];
    expect($half >> 24)->toBeGreaterThan(0x70)->toBeLessThan(0x90)
        ->and(($half >> 16) & 0xFF)->toBe($half >> 24);
});

it('keeps state across save and restore', function (): void {
    [, $c] = pv_canvas();
    plutovg_canvas_set_line_width($c, 3);
    plutovg_canvas_set_operator($c, PLUTOVG_OPERATOR_SRC);
    plutovg_canvas_save($c);
    plutovg_canvas_set_line_width($c, 7);
    plutovg_canvas_translate($c, 5, 0);
    plutovg_canvas_restore($c);

    $m = new plutovg_matrix();
    plutovg_canvas_get_matrix($c, $m);
    expect(plutovg_canvas_get_line_width($c))->toBe(3.0)
        ->and(plutovg_canvas_get_operator($c))->toBe(PLUTOVG_OPERATOR_SRC)
        ->and($m->e)->toBe(0.0);
});

it('answers fill and clip queries', function (): void {
    [, $c] = pv_canvas();
    plutovg_canvas_rect($c, 2, 2, 4, 4);
    $r = new plutovg_rect();
    plutovg_canvas_fill_extents($c, $r);

    expect(plutovg_canvas_fill_contains($c, 3, 3))->toBeTrue()
        ->and(plutovg_canvas_fill_contains($c, 8, 8))->toBeFalse()
        ->and([$r->x, $r->y, $r->w, $r->h])->toBe([2.0, 2.0, 4.0, 4.0]);
});

it('stroke_contains answers as fill_contains in PlutoVG 1.3.3 (kept 1:1)', function (): void {
    [, $c] = pv_canvas(20, 20);
    plutovg_canvas_rect($c, 2, 2, 10, 10);
    plutovg_canvas_set_line_width($c, 1);
    // A point well inside the rect, far from its outline: a stroke test would say false.
    expect(plutovg_canvas_stroke_contains($c, 7, 7))->toBe(plutovg_canvas_fill_contains($c, 7, 7));
});

it('reads back paint, dashes and path', function (): void {
    [, $c] = pv_canvas();
    plutovg_canvas_set_rgba($c, 0, 0, 1, 0.5);
    $color = new plutovg_color();
    expect(plutovg_canvas_get_paint($c, $color))->toBeNull()
        ->and($color->a)->toBe(0.5);

    plutovg_canvas_set_dash($c, 1, [2, 3], 2);
    expect(plutovg_canvas_get_dash_array($c, $dashes))->toBe(2)
        ->and($dashes)->toBe([2.0, 3.0])
        ->and(plutovg_canvas_get_dash_offset($c))->toBe(1.0);

    plutovg_canvas_rect($c, 0, 0, 1, 1);
    expect(plutovg_path_length(plutovg_canvas_get_path($c)))->toBe(4.0);
});

it('refuses enums PlutoVG would index or switch on blindly', function (string $fn, int $arg): void {
    [, $c] = pv_canvas();
    $fn($c, 99);
})->with([
    ['plutovg_canvas_set_operator', 99],
    ['plutovg_canvas_set_fill_rule', 99],
    ['plutovg_canvas_set_line_cap', 99],
    ['plutovg_canvas_set_line_join', 99],
])->throws(ValueError::class);

it('refuses strokes whose dashes PlutoVG would never finish', function (string $how): void {
    [, $c] = pv_canvas();
    plutovg_canvas_set_dash($c, 0, [1e-6], 1);
    match ($how) {
        'stroke' => (function () use ($c) { plutovg_canvas_rect($c, 0, 0, 100, 100); plutovg_canvas_stroke($c); })(),
        'stroke_rect' => plutovg_canvas_stroke_rect($c, 0, 0, 100, 100),
        'stroke_extents' => (function () use ($c) { plutovg_canvas_rect($c, 0, 0, 100, 100); plutovg_canvas_stroke_extents($c, new plutovg_rect()); })(),
    };
})->with(['stroke', 'stroke_rect', 'stroke_extents'])->throws(ValueError::class, 'dashes');

it('refuses adding the canvas path to itself and NaN arcs', function (): void {
    [, $c] = pv_canvas();
    plutovg_canvas_rect($c, 0, 0, 1, 1);
    expect(fn () => plutovg_canvas_add_path($c, plutovg_canvas_get_path($c)))->toThrow(ValueError::class, 'own path')
        ->and(fn () => plutovg_canvas_arc($c, 0, 0, 1, 0, NAN, false))->toThrow(ValueError::class, 'finite');
});

it('textures from a surface kept alive by the canvas', function (): void {
    [$s, $c] = pv_canvas(2, 1);
    $tex = plutovg_surface_create_for_data(pack('V', 0xFF00FF00), 1, 1, 4);
    plutovg_canvas_set_texture($c, $tex, PLUTOVG_TEXTURE_TYPE_TILED, 1, null);
    unset($tex);
    gc_collect_cycles();
    plutovg_canvas_paint($c);

    expect(pv_pixels($s))->toBe([0xFF00FF00, 0xFF00FF00]);
});
