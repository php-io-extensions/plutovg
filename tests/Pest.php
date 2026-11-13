<?php

declare(strict_types=1);

if (! extension_loaded('plutovg')) {
    throw new RuntimeException('The plutovg extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

/** Premultiplied ARGB32 pixels of a surface, row by row. */
function pv_pixels(plutovg_surface $surface): array
{
    return array_values(unpack('V*', plutovg_surface_get_data($surface)));
}

/** A TrueType font on this machine, or null (font tests skip without one). */
function pv_font_file(): ?string
{
    foreach ([
        '/System/Library/Fonts/Supplemental/Arial.ttf',
        '/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf',
        '/usr/share/fonts/TTF/DejaVuSans.ttf',
    ] as $file) {
        if (is_file($file)) {
            return $file;
        }
    }

    return null;
}

function tap(mixed $value, callable $fn): mixed
{
    $fn($value);

    return $value;
}
