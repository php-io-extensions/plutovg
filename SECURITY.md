# Security Policy

## Supported versions

ext-plutovg is pre-1.0. No 0.x release receives security fixes or advisories; fixes land in the
next release line. Security support starts with 1.0.

| Version | Security fixes |
|---------|----------------|
| < 1.0   | No             |

## Reporting a vulnerability

Please don't open a public issue for a security problem.

Report it privately through GitHub: the **Report a vulnerability** button on the
[php-io-extensions/plutovg](https://github.com/php-io-extensions/plutovg) repository's **Security** tab.
If that isn't available, email **info@projectsaturnstudios.com**.

Include what you found, the affected version, your platform and CPU, PHP build (NTS or ZTS), and
steps to reproduce (`php --ri plutovg` shows the extension version and the PlutoVG commit it carries).

A defect in PlutoVG itself belongs with that project. Report it here as well when ext-plutovg should
guard against it.

## Security model

PlutoVG trusts its caller with memory, enum values and float arithmetic. ext-plutovg stands between
PHP and PlutoVG:

- **Fonts and images are trusted input.** Font data goes to stb_truetype, which does not check table
  offsets against the data's length; images go to stb_image. A hostile font file can read out of
  bounds. Load only fonts and images you trust. The binding refuses font data shorter than an offset
  table and checks every length it passes, but it cannot make stb_truetype safe.
- **Memory.** `plutovg_surface_create_for_data` draws into the binding's own copy of the string,
  kept alive by every handle built on the surface (canvases, textures, references). Only
  `plutovg_surface_create_for_address` (a binding addition) draws into memory the binding does not
  own; its caller vouches for the address, and the owner object passed with it is kept alive.
- **Inputs PlutoVG would trust.** Operator values outside the enum (PlutoVG indexes a function-pointer
  table with them), any other enum out of range, a path added to itself, NaN arc angles, path
  reserves that overflow `int`, dash patterns PlutoVG's float dasher would never finish (more than
  2^22 dashes, checked again at every stroke), iterators stepped past their end or past a change,
  text lengths beyond the string, and geometry a pixel string cannot hold: each is a `ValueError`
  before PlutoVG runs. `tools/sweep.php` calls every function with zero, negative, huge, infinite
  and NaN arguments in separate processes to keep it that way.
- **Files.** Every filename and directory goes through `open_basedir`; scanning the system font
  directories is refused while `open_basedir` is set.
- **Symbols.** The module exports `get_module` only, so another PlutoVG in the process (lunasvg,
  plutosvg) never takes over the binding's calls.
- **Callbacks.** Path traversal and image-writer callables run on the calling thread, synchronously.
  After one throws, PlutoVG finishes its walk without calling it again, and the exception surfaces
  when the call returns.
- **Threads.** Every handle is owned by the PHP thread that made it. On macOS PlutoVG's font face
  cache has no lock (no `<threads.h>`); a cache never crosses PHP threads, so none is needed.
