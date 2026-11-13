<?php

declare(strict_types=1);

it('initialises, converts and parses colours', function (): void {
    $c = new plutovg_color();
    plutovg_color_init_rgba8($c, 255, 0, 0, 255);
    expect(plutovg_color_to_argb32($c))->toBe(0xFFFF0000)
        ->and(plutovg_color_to_rgba32($c))->toBe(0xFF0000FF);

    plutovg_color_init_argb32($c, 0x8000FF00);
    expect(round($c->a, 2))->toBe(0.5)->and($c->g)->toBe(1.0);

    expect(plutovg_color_parse($c, '#00f', -1))->toBe(4)
        ->and([$c->r, $c->g, $c->b, $c->a])->toBe([0.0, 0.0, 1.0, 1.0])
        ->and(fn () => plutovg_color_init_rgba32($c, -1))->toThrow(ValueError::class);
});

it('creates surfaces within PlutoVG limits and reads pixels back', function (): void {
    $s = plutovg_surface_create(4, 3);
    expect(plutovg_surface_get_width($s))->toBe(4)
        ->and(plutovg_surface_get_height($s))->toBe(3)
        ->and(plutovg_surface_get_stride($s))->toBe(16)
        ->and(plutovg_surface_get_data_address($s))->not->toBe(0)
        ->and(plutovg_surface_create(0, 1))->toBeNull()
        ->and(plutovg_surface_create(1 << 15, 1))->toBeNull();

    plutovg_surface_clear($s, new plutovg_color(1, 0, 0, 1));
    expect(array_unique(pv_pixels($s)))->toBe([0xFFFF0000]);
});

it('draws into the data it was created for, kept alive by every handle built on it', function (): void {
    $s = plutovg_surface_create_for_data(str_repeat("\0", 64 * 2), 16, 2, 64);
    $canvas = plutovg_canvas_create($s);
    unset($s);
    plutovg_canvas_set_rgba($canvas, 0, 1, 0, 1);
    plutovg_canvas_paint($canvas);
    $surface = plutovg_canvas_get_surface($canvas);
    unset($canvas);
    gc_collect_cycles();

    expect(array_unique(pv_pixels($surface)))->toBe([0xFF00FF00]);
});

it('refuses create_for_data geometry the string cannot hold', function (int $w, int $h, int $stride, string $data): void {
    plutovg_surface_create_for_data($data, $w, $h, $stride);
})->with([
    'short data' => [4, 4, 16, str_repeat("\0", 63)],
    'stride below a row' => [4, 1, 12, str_repeat("\0", 16)],
    'zero width' => [0, 1, 16, str_repeat("\0", 16)],
])->throws(ValueError::class);

it('draws into memory it is pointed at, keeping the owner alive', function (): void {
    $owner = plutovg_surface_create(8, 8);
    $s = plutovg_surface_create_for_address(plutovg_surface_get_data_address($owner), 8, 8, 32, $owner);
    $c = plutovg_canvas_create($s);
    plutovg_canvas_set_rgb($c, 0, 0, 1);
    plutovg_canvas_paint($c);

    expect(array_unique(pv_pixels($owner)))->toBe([0xFF0000FF])
        ->and(fn () => plutovg_surface_create_for_address(0, 1, 1, 4, $owner))->toThrow(ValueError::class);
});

it('round-trips PNG through a stream and data, and JPG through a stream', function (): void {
    $s = plutovg_surface_create(5, 4);
    plutovg_surface_clear($s, new plutovg_color(0, 0, 1, 1));
    $png = '';
    expect(plutovg_surface_write_to_png_stream($s, function (string $data, int $size) use (&$png): void {
        expect(strlen($data))->toBe($size);
        $png .= $data;
    }))->toBeTrue();

    $back = plutovg_surface_load_from_image_data($png, -1);
    expect(plutovg_surface_get_width($back))->toBe(5)
        ->and(array_unique(pv_pixels($back)))->toBe([0xFF0000FF])
        ->and(plutovg_surface_load_from_image_base64(base64_encode($png), -1))->toBeInstanceOf(plutovg_surface::class)
        ->and(plutovg_surface_load_from_image_data('not an image', -1))->toBeNull();

    $jpg = '';
    plutovg_surface_write_to_jpg_stream($s, function (string $data) use (&$jpg): void { $jpg .= $data; }, 90);
    expect(substr($jpg, 0, 2))->toBe("\xFF\xD8");
});

it('writes and loads PNG files', function (): void {
    $file = tempnam(sys_get_temp_dir(), 'pvg') . '.png';
    $s = plutovg_surface_create(3, 3);
    expect(plutovg_surface_write_to_png($s, $file))->toBeTrue()
        ->and(plutovg_surface_get_width(plutovg_surface_load_from_image_file($file)))->toBe(3);
    unlink($file);
});

it('converts premultiplied ARGB to RGBA and back', function (): void {
    $argb = pack('V', 0xFF112233);
    plutovg_convert_argb_to_rgba($rgba, $argb, 1, 1, 4);
    expect(bin2hex($rgba))->toBe('112233ff');

    plutovg_convert_rgba_to_argb($back, $rgba, 1, 1, 4);
    expect($back)->toBe($argb)
        ->and(fn () => plutovg_convert_argb_to_rgba($x, 'abc', 1, 1, 4))->toThrow(ValueError::class);
});

it('creates paints and counts references', function (): void {
    $stops = [new plutovg_gradient_stop(0, new plutovg_color(1, 0, 0, 1)), new plutovg_gradient_stop(1, new plutovg_color(0, 0, 1, 1))];
    $paints = [
        plutovg_paint_create_rgb(1, 0, 0),
        plutovg_paint_create_color(new plutovg_color(0, 1, 0, 1)),
        plutovg_paint_create_linear_gradient(0, 0, 10, 0, PLUTOVG_SPREAD_METHOD_PAD, $stops, 2, null),
        plutovg_paint_create_radial_gradient(5, 5, 5, 5, 5, 0, PLUTOVG_SPREAD_METHOD_REFLECT, $stops, 2, new plutovg_matrix(1, 0, 0, 1, 0, 0)),
        plutovg_paint_create_texture(plutovg_surface_create(2, 2), PLUTOVG_TEXTURE_TYPE_TILED, 1, null),
    ];
    $ref = plutovg_paint_reference($paints[0]);
    expect(plutovg_paint_get_reference_count($paints[0]))->toBe(2);
    plutovg_paint_destroy($ref);
    expect(plutovg_paint_get_reference_count($paints[0]))->toBe(1)
        ->and(fn () => plutovg_paint_get_reference_count($ref))->toThrow(ValueError::class, 'released')
        ->and(fn () => plutovg_paint_create_linear_gradient(0, 0, 1, 0, 7, $stops, 2, null))->toThrow(ValueError::class)
        ->and(fn () => plutovg_paint_create_linear_gradient(0, 0, 1, 0, 0, $stops, 3, null))->toThrow(ValueError::class);
});

it('reads the alpha plane packed, one byte a pixel (binding addition)', function (): void {
    $s = plutovg_surface_create_for_data(pack('V*', 0x80FFFFFF, 0x00000000, 0xFF000000, 0x40102030, 0, 0), 2, 2, 12);
    expect(bin2hex(plutovg_surface_get_alpha($s)))->toBe('80004000') // row 1 starts at the stride, skipping the third word
        ->and(fn () => plutovg_surface_get_alpha(tap(plutovg_surface_create(1, 1), fn ($x) => plutovg_surface_destroy($x))))->toThrow(ValueError::class);
});
