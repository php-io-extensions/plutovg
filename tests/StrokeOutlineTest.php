<?php

/*
 * plutovg_path_stroke_outline(): a binding addition that runs PlutoVG's internal stroker and
 * hands the outline back. Filled, it must give exactly the pixels plutovg_canvas_stroke_path() draws.
 */

function pvBox(plutovg_path $p): array
{
    $r = new plutovg_rect();
    plutovg_path_extents($p, $r, true);

    return [$r->x, $r->y, $r->w, $r->h];
}

it('outlines a butt-capped line as its rectangle', function () {
    $p = plutovg_path_create();
    plutovg_path_move_to($p, 10, 10);
    plutovg_path_line_to($p, 50, 10);

    expect(pvBox(plutovg_path_stroke_outline($p, 8, PLUTOVG_LINE_CAP_BUTT, PLUTOVG_LINE_JOIN_MITER, 10)))
        ->toBe([10.0, 6.0, 40.0, 8.0]);
});

it('extends square and round caps by half the width', function (int $cap) {
    $p = plutovg_path_create();
    plutovg_path_move_to($p, 10, 10);
    plutovg_path_line_to($p, 50, 10);

    expect(pvBox(plutovg_path_stroke_outline($p, 8, $cap, PLUTOVG_LINE_JOIN_MITER, 10)))
        ->toBe([6.0, 6.0, 48.0, 8.0]);
})->with([PLUTOVG_LINE_CAP_SQUARE, PLUTOVG_LINE_CAP_ROUND]);

it('fills to exactly what plutovg_canvas_stroke_path draws', function () {
    mt_srand(7);
    for ($n = 0; $n < 40; $n++) {
        $p = plutovg_path_create();
        plutovg_path_move_to($p, mt_rand(5, 95), mt_rand(5, 95));
        for ($k = 0; $k < mt_rand(1, 4); $k++) {
            mt_rand(0, 1)
                ? plutovg_path_line_to($p, mt_rand(5, 95), mt_rand(5, 95))
                : plutovg_path_cubic_to($p, mt_rand(5, 95), mt_rand(5, 95), mt_rand(5, 95), mt_rand(5, 95), mt_rand(5, 95), mt_rand(5, 95));
        }
        $w = mt_rand(1, 12);
        $cap = mt_rand(0, 2);
        $join = mt_rand(0, 2);

        $a = plutovg_surface_create(100, 100);
        $c = plutovg_canvas_create($a);
        plutovg_canvas_set_rgba($c, 1, 1, 1, 1);
        plutovg_canvas_set_line_width($c, $w);
        plutovg_canvas_set_line_cap($c, $cap);
        plutovg_canvas_set_line_join($c, $join);
        plutovg_canvas_set_miter_limit($c, 10);
        plutovg_canvas_stroke_path($c, $p);

        $b = plutovg_surface_create(100, 100);
        $d = plutovg_canvas_create($b);
        plutovg_canvas_set_rgba($d, 1, 1, 1, 1);
        plutovg_canvas_set_fill_rule($d, PLUTOVG_FILL_RULE_NON_ZERO);
        plutovg_canvas_fill_path($d, plutovg_path_stroke_outline($p, $w, $cap, $join, 10));

        expect(plutovg_surface_get_alpha($b))->toBe(plutovg_surface_get_alpha($a));
    }
});

it('refuses widths, caps, joins and points it cannot stroke', function (array $args, int $arg) {
    $p = plutovg_path_create();
    plutovg_path_move_to($p, ...($args[4] ?? [0, 0]));
    plutovg_path_line_to($p, 10, 0);
    expect(fn () => plutovg_path_stroke_outline($p, $args[0], $args[1], $args[2], $args[3]))
        ->toThrow(ValueError::class, "Argument #$arg");
})->with([
    'nan width' => [[NAN, 0, 0, 10], 2],
    'negative width' => [[-1, 0, 0, 10], 2],
    'cap' => [[4, 9, 0, 10], 3],
    'join' => [[4, 0, -1, 10], 4],
    'miter' => [[4, 0, 0, INF], 5],
    'point' => [[4, 0, 0, 10, [INF, 0]], 1],
]);
