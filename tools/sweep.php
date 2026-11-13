<?php

/*
 * Crash sweep: calls every plutovg_* function with argument sets built from its
 * signature, each call in its own child process. A PHP exception is a pass; a
 * signal (segfault, SIGFPE, abort) or a hang is a failure. Run after any change
 * to argument checks:  php -d memory_limit=256M tools/sweep.php
 *
 * Skipped: plutovg_surface_create_for_address, whose caller vouches for the address.
 * Children run in a scratch directory: the file-writing functions get junk names.
 */

declare(strict_types=1);

if ($argc > 2 && $argv[1] === '--one') {
    [$name, $variant] = explode(':', $argv[2]);
    $f = new ReflectionFunction($name);
    $args = [];
    foreach ($f->getParameters() as $p) {
        $args[] = sweep_value($p, (int) $variant);
    }
    try {
        $f->invokeArgs($args);
    } catch (Throwable) {
    }
    exit(0);
}

function sweep_value(ReflectionParameter $p, int $v): mixed
{
    $type = $p->getType();
    $name = $type instanceof ReflectionNamedType ? $type->getName() : 'mixed';
    $int = [0, -1, 1 << 20, PHP_INT_MAX, 7][$v];
    return match ($name) {
        'int' => $int,
        'float' => [0.0, -1.0, 1e9, INF, NAN][$v],
        'bool' => $v % 2 === 1,
        'string' => ['', "\xff", str_repeat("\x01", 64), str_repeat("\0", 4096), 'abcd'][$v],
        'array' => [[], [0], [1, 2, 3], array_fill(0, 9, 1 << 16), [new plutovg_point(), new plutovg_gradient_stop()]][$v],
        'callable' => fn (...$a) => 0,
        'mixed' => null,
        'plutovg_surface' => [plutovg_surface_create(2, 2), plutovg_surface_create(1, 1), plutovg_surface_create(300, 7), sweep_released('surface'), plutovg_surface_create_for_data(str_repeat("\0", 64), 4, 2, 32)][$v],
        'plutovg_canvas' => sweep_canvas($v),
        'plutovg_paint' => [plutovg_paint_create_rgb(1, 0, 0), plutovg_paint_create_linear_gradient(0, 0, 1, 1, 0, [], 0, null), plutovg_paint_create_texture(plutovg_surface_create(1, 1), 1, 1, null), sweep_released('paint'), plutovg_paint_create_rgba(NAN, INF, -1, 2)][$v],
        'plutovg_path' => sweep_path($v),
        'plutovg_font_face' => sweep_face($v),
        'plutovg_font_face_cache' => plutovg_font_face_cache_create(),
        default => class_exists($name) ? sweep_struct($name, $v) : null,
    };
}

function sweep_released(string $kind): object
{
    $h = match ($kind) {
        'surface' => plutovg_surface_create(1, 1),
        'paint' => plutovg_paint_create_rgb(0, 0, 0),
    };
    ('plutovg_' . $kind . '_destroy')($h);

    return $h;
}

function sweep_path(int $v): plutovg_path
{
    $p = plutovg_path_create();
    match ($v) {
        1 => plutovg_path_add_circle($p, 0, 0, 1e9),
        2 => plutovg_path_add_rect($p, NAN, 0, INF, 1),
        3 => plutovg_path_destroy($p),
        4 => plutovg_path_parse($p, 'M0 0 C1 1 2 2 3 3 A5 5 0 1 1 9 9 Z', -1),
        default => null,
    };

    return $p;
}

function sweep_canvas(int $v): plutovg_canvas
{
    $c = plutovg_canvas_create(plutovg_surface_create(16, 16));
    match ($v) {
        1 => plutovg_canvas_rect($c, -1e9, -1e9, 2e9, 2e9),
        2 => (function () use ($c) { plutovg_canvas_set_dash($c, 0, [0.5, 0.5], 2); plutovg_canvas_circle($c, 8, 8, 6); })(),
        3 => plutovg_canvas_destroy($c),
        4 => (function () use ($c) { plutovg_canvas_scale($c, 0, 0); plutovg_canvas_move_to($c, NAN, INF); plutovg_canvas_line_to($c, 1, 1); })(),
        default => null,
    };

    return $c;
}

function sweep_face(int $v): plutovg_font_face
{
    static $file = null;
    $file ??= array_values(array_filter(['/System/Library/Fonts/Supplemental/Arial.ttf', '/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf'], 'is_file'))[0];
    $f = plutovg_font_face_load_from_file($file, 0);
    if ($v === 3) {
        plutovg_font_face_destroy($f);
    }

    return $f;
}

function sweep_struct(string $class, int $v): object
{
    $o = new $class();
    if ($v === 0) {
        return $o;
    }
    foreach ((new ReflectionClass($o))->getProperties() as $prop) {
        $t = $prop->getType()?->getName();
        if ($t === 'int') {
            $prop->setValue($o, [0, -1, 1 << 20, 0x7fffffff, 3][$v]);
        } elseif ($t === 'float') {
            $prop->setValue($o, [0.0, -1.0, 1e9, INF, NAN][$v]);
        }
    }

    return $o;
}

$fails = [];
$functions = array_values(array_diff(get_extension_funcs('plutovg'), ['plutovg_surface_create_for_address']));
$cwd = sys_get_temp_dir() . '/plutovg-sweep-' . getmypid();
@mkdir($cwd);
sort($functions);
foreach ($functions as $fn) {
    for ($variant = 0; $variant < 5; $variant++) {
        $p = proc_open([PHP_BINARY, '-d', 'memory_limit=256M', __FILE__, '--one', "$fn:$variant"], [1 => ['file', '/dev/null', 'w'], 2 => ['file', '/dev/null', 'w']], $pipes, $cwd);
        $start = microtime(true);
        while (($s = proc_get_status($p))['running'] && microtime(true) - $start < 10) {
            usleep(2000);
        }
        if ($s['running']) {
            proc_terminate($p, 9);
            $fails[] = "$fn:$variant hang";
        } elseif ($s['signaled'] || $s['exitcode'] !== 0) {
            $fails[] = "$fn:$variant " . ($s['signaled'] ? 'signal ' . $s['termsig'] : 'exit ' . $s['exitcode']);
        }
        proc_close($p);
    }
}
echo count($functions) * 5, ' calls, ', count($fails), " failures\n", implode("\n", $fails), "\n";
array_map('unlink', glob($cwd . '/{,.}*[!.]*', GLOB_BRACE) ?: []);
@rmdir($cwd);
exit($fails === [] ? 0 : 1);
