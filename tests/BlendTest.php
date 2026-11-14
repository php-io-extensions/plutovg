<?php

declare(strict_types=1);

/** VelvetGE's blend of straight colour $col at coverage $c into straight pixel $d (RGBA). */
function velvetBlend(array $d, array $col, int $c): array
{
    $a = intdiv($col[3] * $c + 127, 255);
    if ($a === 0) {
        return $d;
    }
    if ($a === 255) {
        return [$col[0], $col[1], $col[2], 255];
    }
    $k = 255 - $a;

    return [intdiv($col[0] * $a + $d[0] * $k + 127, 255), intdiv($col[1] * $a + $d[1] * $k + 127, 255), intdiv($col[2] * $a + $d[2] * $k + 127, 255), intdiv(255 * $a + $d[3] * $k + 127, 255)];
}

it('blends a colour through coverage with VelvetGE arithmetic in every byte order', function (int $order, array $off) {
    [$W, $H] = [16, 4];
    $cov = plutovg_surface_create($W, $H);
    $cv = plutovg_canvas_create($cov);
    plutovg_canvas_set_rgba($cv, 1, 1, 1, 1);
    $p = plutovg_path_create();
    plutovg_path_add_ellipse($p, 8, 2, 6.3, 1.7);
    plutovg_canvas_fill_path($cv, $p);
    $alpha = plutovg_surface_get_alpha($cov);

    $mem = plutovg_surface_create($W, $H);
    [$addr, $stride] = [plutovg_surface_get_data_address($mem), plutovg_surface_get_stride($mem)];
    $full = plutovg_surface_create($W, $H);
    plutovg_canvas_set_rgba($fc = plutovg_canvas_create($full), 1, 1, 1, 1);
    plutovg_canvas_paint($fc);
    plutovg_surface_blend_colour($full, $addr, $W, $H, $stride, $order, 0, 0, (40 << 24) | (90 << 16) | (200 << 8) | 255);

    $col = [250, 30, 60, 180];
    $box = plutovg_surface_blend_colour($cov, $addr, $W, $H, $stride, $order, 0, 0, ($col[0] << 24) | ($col[1] << 16) | ($col[2] << 8) | $col[3]);
    $bytes = plutovg_surface_get_data($mem);
    for ($y = 0; $y < $H; $y++) {
        for ($x = 0; $x < $W; $x++) {
            $px = substr($bytes, $y * $stride + $x * 4, 4);
            expect([ord($px[$off[0]]), ord($px[$off[1]]), ord($px[$off[2]]), ord($px[$off[3]])])
                ->toBe(velvetBlend([40, 90, 200, 255], $col, ord($alpha[$y * $W + $x])));
        }
    }
    expect($box)->toBe([1, 0, 14, 4]);
})->with([
    'RGBA' => [PLUTOVG_MEMORY_RGBA, [0, 1, 2, 3]],
    'BGRA' => [PLUTOVG_MEMORY_BGRA, [2, 1, 0, 3]],
    'ARGB' => [PLUTOVG_MEMORY_ARGB, [1, 2, 3, 0]],
    'ABGR' => [PLUTOVG_MEMORY_ABGR, [3, 2, 1, 0]],
]);

it('samples a ramp by VelvetGE rule and checks its arguments', function () {
    $cov = plutovg_surface_create(4, 1);
    plutovg_canvas_set_rgba($c = plutovg_canvas_create($cov), 1, 1, 1, 1);
    plutovg_canvas_paint($c);
    $mem = plutovg_surface_create(4, 1);
    $ramp = '';
    for ($i = 0; $i < 256; $i++) {
        $ramp .= chr($i).chr(255 - $i)."\x00\xff";
    }
    // u = x / 4 across the row: pixel centres 0.125, 0.375, 0.625, 0.875
    plutovg_surface_blend_ramp($cov, plutovg_surface_get_data_address($mem), 4, 1, 16, PLUTOVG_MEMORY_RGBA, 0, 0, $ramp, false, PLUTOVG_SPREAD_METHOD_PAD, [0.25, 0, 0, 0, 0, 0]);
    $reds = array_map(fn ($i) => ord(plutovg_surface_get_data($mem)[$i * 4]), range(0, 3));

    expect($reds)->toBe(array_map(fn ($t) => (int) floor($t * 255 + 0.5), [0.125, 0.375, 0.625, 0.875]))
        ->and(fn () => plutovg_surface_blend_ramp($cov, 1, 4, 1, 16, 0, 0, 0, 'short', false, 0, [1, 0, 0, 1, 0, 0]))->toThrow(ValueError::class)
        ->and(fn () => plutovg_surface_blend_colour($cov, 1, 4, 1, 15, 0, 0, 0, 0))->toThrow(ValueError::class)
        ->and(fn () => plutovg_surface_blend_colour($cov, 1, 4, 1, 16, 9, 0, 0, 0))->toThrow(ValueError::class);
});
