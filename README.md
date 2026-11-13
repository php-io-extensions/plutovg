<div align="center" id="header">

<h1>ext-plutovg</h1>

<h3>PlutoVG 1.3.3 bound 1:1 into PHP 8.4+, with the library compiled in</h3>


[![CI](https://img.shields.io/github/actions/workflow/status/php-io-extensions/plutovg/ci.yml?style=flat-square&label=CI)](https://github.com/php-io-extensions/plutovg/actions/workflows/ci.yml)
[![Packagist](https://img.shields.io/packagist/v/php-io-extensions/plutovg?style=flat-square)](https://packagist.org/packages/php-io-extensions/plutovg)
[![PHP](https://img.shields.io/packagist/dependency-v/php-io-extensions/plutovg/php?style=flat-square&label=PHP)](https://packagist.org/packages/php-io-extensions/plutovg)
[![License](https://img.shields.io/github/license/php-io-extensions/plutovg?style=flat-square)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux_%7C_macos-blue?style=flat-square&logo=linux&logoColor=white)](https://github.com/sammycage/plutovg)
[![PIE](https://img.shields.io/badge/PIE-installable-4f5b93?style=flat-square&logo=php&logoColor=white)](https://github.com/php/pie)

</div>

Vector drawing in software means turning paths into pixels: filling curves with the right winding rule, stroking them with joins, caps and dashes, anti-aliasing every edge, painting gradients and textures through a transform, and laying out text from a font. Doing that in PHP is slow and full of edge cases.

<b>PlutoVG</b> does it in one small C library: a cairo-like canvas over ARGB32 surfaces, paths with Béziers, arcs and SVG path data, FreeType-derived anti-aliased rasterisation and stroking, linear, radial and texture paints, Porter-Duff operators, TrueType text through stb_truetype, and PNG/JPG in and out.

<b>The only problem?</b> PHP can't reach it. This extension binds every public function of `plutovg.h` one to one under the C names, with PlutoVG compiled into the module from an unchanged copy of the upstream tag, so there is nothing to install from the system. Structs are typed classes, surfaces, canvases, paints, paths and fonts are objects holding one reference, pixels cross as strings, and every argument PlutoVG would trust blindly is checked first. No defaults, no composites, no opinions: what PlutoVG documents is what you call.

## Basic usage

```php
<?php
// A blue disc with a dashed white ring, on a 64×64 surface.
$surface = plutovg_surface_create(64, 64);
$canvas = plutovg_canvas_create($surface);

plutovg_canvas_set_rgb($canvas, 0.1, 0.4, 0.9);
plutovg_canvas_circle($canvas, 32, 32, 24);
plutovg_canvas_fill($canvas);

plutovg_canvas_set_rgba($canvas, 1, 1, 1, 0.8);
plutovg_canvas_set_line_width($canvas, 4);
plutovg_canvas_set_dash($canvas, 0, [6, 4], 2);
plutovg_canvas_circle($canvas, 32, 32, 24);
plutovg_canvas_stroke($canvas);

// Pixels are premultiplied ARGB32 in native byte order.
printf("%08x\n", unpack('V*', plutovg_surface_get_data($surface))[32 * 64 + 33]); // ff1a66e6
plutovg_surface_write_to_png($surface, 'circle.png');
```

## Requirements

- PHP 8.4 or newer, NTS or ZTS, with `phpize` and `php-config`.
- A C compiler.
- No system libraries.

```bash
# Debian, Ubuntu, Raspberry Pi OS
sudo apt install build-essential php8.4-dev

# macOS: Xcode Command Line Tools, and Homebrew's PHP ships phpize and php-config
xcode-select --install
```

## Installation

### With PHP PIE (recommended)

```bash
pie install php-io-extensions/plutovg
```

### Manually (install script)

```bash
git clone https://github.com/php-io-extensions/plutovg.git
cd plutovg

./install-debian-trixie.sh             # Debian Trixie, Ubuntu 24.04+, Raspberry Pi OS: the php on PATH
./install-macos.sh                     # Homebrew php@8.4 and php@8.4-zts
./install-macos.sh /path/to/bin/php    # either script takes specific PHP binaries
```

### Manually (phpize)

```bash
git clone https://github.com/php-io-extensions/plutovg.git
cd plutovg
phpize
./configure --enable-plutovg
make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
sudo make install
```

Then add `extension=plutovg.so` to your `php.ini`, or to a file in the scan directory `php --ini` reports.

### Verify

```console
$ php --ri plutovg

plutovg

plutovg support => enabled
Version => 0.11.x
PlutoVG version => 1.3.3
PlutoVG commit => bbd91f0d06a71491691b36330f29dffa4af87ccf
```

## API

All 212 of PlutoVG's public functions, under their C names, plus three additions. The full rules are in the [design spec](docs/superpowers/specs/2026-11-13-plutovg-design.md).

### Translations

- **Constants:** every enum value (`PLUTOVG_OPERATOR_*`, `PLUTOVG_LINE_CAP_*`, `PLUTOVG_TEXT_ENCODING_*`, …), `PLUTOVG_VERSION*`, and the float constants `PLUTOVG_PI`, `PLUTOVG_KAPPA`, ….
- **Value structs** are final classes named after the C type without `_t` (`plutovg_point`, `plutovg_rect`, `plutovg_matrix`, `plutovg_color`, `plutovg_gradient_stop`), one typed property per field, every constructor argument optional and zero by default. A struct PlutoVG writes, such as a matrix being initialised or extents being measured, is written back into the object you passed. `plutovg_path_get_elements()` returns the element union as `plutovg_path_element` objects with either a `header` or a `point`.
- **Handles** (`plutovg_surface`, `plutovg_canvas`, `plutovg_paint`, `plutovg_path`, `plutovg_font_face`, `plutovg_font_face_cache`) come from the `*_create` and `*_load_*` functions and hold one PlutoVG reference. `*_reference()` returns a second object; `*_destroy()` releases the object you pass. Getters that return a pointer PlutoVG keeps (`plutovg_canvas_get_surface()`, `plutovg_font_face_cache_get()`, …) give an object with its own reference.
- **Iterators** (`plutovg_path_iterator`, `plutovg_text_iterator`) are objects you `new` and pass to `*_init`; they hold their path or string.
- **Out-parameters:** C `float *` and arrays PlutoVG fills are PHP references (`plutovg_matrix_map($m, $x, $y, $xx, $yy)`).
- **Pixels cross as strings.** `plutovg_surface_get_data()` returns a copy. `plutovg_surface_create_for_data()` draws into its own copy of your string, which every canvas, texture and reference built on the surface keeps alive. `plutovg_convert_*` write their result to a reference.
- **Lengths:** a `-1` length means the whole string (for text: up to the first zero unit inside it).
- **Callbacks:** `destroy_func`/`closure` pairs are the binding's own (font data is copied and freed with the face); traversal and image-writer functions take a PHP callable in place of the function/closure pair.
- **Additions:** `plutovg_surface_get_alpha()` returns a surface's alpha plane as packed bytes (for a white fill, its a8 coverage), `plutovg_surface_get_data_address()` returns the address of a surface's pixels, and `plutovg_surface_create_for_address()` makes a surface over memory another extension owns (a pixman image's bits, for example), keeping the owner object you pass alive.

### Callbacks

Path traversal (`plutovg_path_traverse*`, `plutovg_font_face_traverse_glyph_path`) calls `fn(int $command, array $points, int $npoints)`; the image writers call `fn(string $data, int $size)`. They run on the calling thread, during the call. After one throws, PlutoVG finishes without calling it again and the exception surfaces when the call returns.

### Errors

PlutoVG reports failure through return values, which come back as `false`, `null` or `0`. Arguments PlutoVG would trust and crash or hang on are a `ValueError` before it runs: an operator or other enum out of range, a path added to itself, a NaN arc angle, a reserve that overflows, a dash pattern of more than 2^22 dashes, an iterator past its end or past a change to its path, a length beyond its string, and pixel geometry a string cannot hold.

### Upstream behaviour kept as is

PlutoVG 1.3.3 never joins UTF-16 surrogate pairs (each half comes out as its own code point), and `plutovg_canvas_stroke_contains()` tests the fill, not the stroke. The binding keeps both, 1:1.

## Running the test suite

```bash
composer install
php -d memory_limit=128M vendor/bin/pest
php -d memory_limit=256M tools/sweep.php   # crash sweep: every function, five argument sets, one process each
```

The font tests use a TrueType font found on the machine (Arial on macOS, DejaVu Sans on Debian) and skip without one.

## Security

See [SECURITY.md](SECURITY.md). Fonts and images are trusted input.

## License

MIT for this extension. PlutoVG is MIT, [lib/plutovg/LICENSE](lib/plutovg/LICENSE); its FreeType-derived rasteriser is under the FreeType License, [lib/plutovg/source/FTL.TXT](lib/plutovg/source/FTL.TXT).
