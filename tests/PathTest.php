<?php

declare(strict_types=1);

it('builds, multiplies, inverts and maps matrices', function (): void {
    $m = new plutovg_matrix();
    plutovg_matrix_init_translate($m, 10, 20);
    plutovg_matrix_scale($m, 2, 2);
    plutovg_matrix_map($m, 1, 1, $x, $y);
    expect([$x, $y])->toBe([12.0, 22.0]);

    $inverse = new plutovg_matrix();
    expect(plutovg_matrix_invert($m, $inverse))->toBeTrue()
        ->and(plutovg_matrix_invert(new plutovg_matrix(), null))->toBeFalse();

    plutovg_matrix_map_points($inverse, [new plutovg_point($x, $y)], $points, 1);
    expect([$points[0]->x, $points[0]->y])->toBe([1.0, 1.0]);

    $r = new plutovg_rect();
    plutovg_matrix_map_rect($m, new plutovg_rect(0, 0, 5, 5), $r);
    expect([$r->x, $r->y, $r->w, $r->h])->toBe([10.0, 20.0, 10.0, 10.0]);

    expect(plutovg_matrix_parse($m, 'scale(3)', -1))->toBeTrue()
        ->and($m->a)->toBe(3.0);
});

it('refuses a map_points count past the list', function (): void {
    plutovg_matrix_map_points(new plutovg_matrix(), [new plutovg_point()], $out, 2);
})->throws(ValueError::class);

it('builds a path and reads it back element by element', function (): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 10, 5);

    expect(plutovg_path_length($p))->toBe(30.0)
        ->and(plutovg_path_get_elements($p, $elements))->toBe(12)
        ->and($elements[0]->header->command)->toBe(PLUTOVG_PATH_COMMAND_MOVE_TO)
        ->and($elements[1]->point->x)->toBe(0.0)
        ->and($elements[3]->point->x)->toBe(10.0);

    $extents = new plutovg_rect();
    plutovg_path_extents($p, $extents, true);
    expect([$extents->x, $extents->y, $extents->w, $extents->h])->toBe([0.0, 0.0, 10.0, 5.0]);

    plutovg_path_get_current_point($p, $x, $y);
    expect([$x, $y])->toBe([0.0, 0.0]);
});

it('iterates commands, and refuses past the end or after the path changed', function (): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 10, 5);
    $it = new plutovg_path_iterator();
    plutovg_path_iterator_init($it, $p);

    $commands = [];
    while (plutovg_path_iterator_has_next($it)) {
        $commands[] = plutovg_path_iterator_next($it, $points);
    }
    expect($commands)->toBe([0, 1, 1, 1, 1, 3])
        ->and(fn () => plutovg_path_iterator_next($it, $points))->toThrow(ValueError::class, 'at the end');

    plutovg_path_iterator_init($it, $p);
    plutovg_path_reserve($p, 1000);
    expect(fn () => plutovg_path_iterator_next($it, $points))->toThrow(ValueError::class, 'changed or was released');
});

it('traverses plain, flattened and dashed', function (): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 10, 5);
    $calls = 0;
    $count = function (int $command, array $points, int $n) use (&$calls): void {
        expect($points)->toHaveCount($n);
        $calls++;
    };

    plutovg_path_traverse($p, $count);
    expect($calls)->toBe(6);

    $calls = 0;
    plutovg_path_traverse_dashed($p, 0, [2, 1], 2, $count);
    expect($calls)->toBe(22);

    $c = plutovg_path_create();
    plutovg_path_add_circle($c, 0, 0, 10);
    $calls = 0;
    plutovg_path_traverse_flatten($c, $count);
    expect($calls)->toBeGreaterThan(6);
});

it('stops calling a traversal callable after it throws', function (): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 10, 5);
    $calls = 0;
    expect(function () use ($p, &$calls): void {
        plutovg_path_traverse($p, function () use (&$calls): void {
            $calls++;
            throw new RuntimeException('stop');
        });
    })->toThrow(RuntimeException::class, 'stop')
        ->and($calls)->toBe(1);
});

it('refuses dash patterns PlutoVG would never finish', function (array $dashes): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 10, 5);
    plutovg_path_clone_dashed($p, 0, $dashes, count($dashes));
})->with([
    'negative' => [[2, -1]],
    'NaN' => [[NAN]],
    'tiny' => [[1e-9]],
])->throws(ValueError::class);

it('refuses adding a path to itself, a NaN arc and an oversized reserve', function (): void {
    $p = plutovg_path_create();
    plutovg_path_add_rect($p, 0, 0, 1, 1);
    $q = plutovg_path_reference($p);

    expect(fn () => plutovg_path_add_path($p, $q, null))->toThrow(ValueError::class, 'same path')
        ->and(fn () => plutovg_path_add_arc($p, 0, 0, 1, NAN, 1, false))->toThrow(ValueError::class, 'finite')
        ->and(fn () => plutovg_path_reserve($p, PHP_INT_MAX))->toThrow(ValueError::class)
        ->and(fn () => plutovg_path_reserve($p, -1))->toThrow(ValueError::class);
});

it('counts references and refuses a released path', function (): void {
    $p = plutovg_path_create();
    $q = plutovg_path_reference($p);
    expect(plutovg_path_get_reference_count($p))->toBe(2);

    plutovg_path_destroy($q);
    expect(plutovg_path_get_reference_count($p))->toBe(1)
        ->and(fn () => plutovg_path_length($q))->toThrow(ValueError::class, 'released');
});

it('parses SVG path data within the given length', function (): void {
    $p = plutovg_path_create();
    expect(plutovg_path_parse($p, 'M0 0 L10 0 L10 10 Z', -1))->toBeTrue()
        ->and(round(plutovg_path_length($p), 3))->toBe(34.142)
        ->and(fn () => plutovg_path_parse($p, 'M0 0', 99))->toThrow(ValueError::class);
});

it('iterates text in each encoding', function (string $text, int $encoding, array $want): void {
    $it = new plutovg_text_iterator();
    plutovg_text_iterator_init($it, $text, -1, $encoding);
    $got = [];
    while (plutovg_text_iterator_has_next($it)) {
        $got[] = plutovg_text_iterator_next($it);
    }
    expect($got)->toBe($want)
        ->and(fn () => plutovg_text_iterator_next($it))->toThrow(ValueError::class, 'at the end');
})->with([
    'latin1' => ["h\xe9", PLUTOVG_TEXT_ENCODING_LATIN1, [0x68, 0xE9]],
    'utf8' => ['hé', PLUTOVG_TEXT_ENCODING_UTF8, [0x68, 0xE9]],
    // PlutoVG 1.3.3 never joins a surrogate pair: it tests the lead unit against 0xDC00. Kept 1:1.
    'utf16 (upstream surrogate bug)' => [mb_convert_encoding('h😀', 'UTF-16LE', 'UTF-8'), PLUTOVG_TEXT_ENCODING_UTF16, [0x68, 0xD83D, 0xDE00]],
    'utf32' => [mb_convert_encoding('h😀', 'UTF-32LE', 'UTF-8'), PLUTOVG_TEXT_ENCODING_UTF32, [0x68, 0x1F600]],
    'stops at a zero unit' => ["ab\0cd", PLUTOVG_TEXT_ENCODING_UTF8, [0x61, 0x62]],
]);

it('refuses a text length past the string and an unknown encoding', function (): void {
    $it = new plutovg_text_iterator();
    expect(fn () => plutovg_text_iterator_init($it, 'ab', 2, PLUTOVG_TEXT_ENCODING_UTF16))->toThrow(ValueError::class)
        ->and(fn () => plutovg_text_iterator_init($it, 'ab', -1, 9))->toThrow(ValueError::class);
});

it('refuses cloning handles', function (): void {
    clone plutovg_path_create();
})->throws(Error::class);
