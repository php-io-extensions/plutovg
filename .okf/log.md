# Log

- 2026-11-15: addition `plutovg_path_stroke_outline()`: PlutoVG's internal FreeType-derived stroker (plutovg-ft-stroker.c) run on a path and exported as a new path. Filled, it matches `plutovg_canvas_stroke_path()` pixel for pixel (40 random paths in StrokeOutlineTest). Pest 69 passed on NTS and ZTS; sweep clean.
- 2026-11-15: `plutovg_surface_get_data()` now returns the address by default; `$copy: true` returns the string copy (not copying is the default).
- 2026-11-15: `plutovg_surface_get_data()` takes `bool $copy = true`; false returns the pixel address C returns, copying nothing. The `plutovg_surface_get_data_address()` addition is removed (it did the same). Pest 57 passed on NTS and ZTS.
- 2026-11-13: added plutovg_surface_blend_colour / _ramp and PLUTOVG_MEMORY_* for venusian-pluto's painting brush; BlendTest checks them against VelvetGE's formula.
- 2026-11-13: ext-plutovg built: all 212 functions + 2 additions; Pest green on php84 NTS + ZTS.

* **2026-11-14**: `plutovg_convert_argb_to_rgba` / `_rgba_to_argb` take `string|int` sources; a `$dst` holding a trusted address is written in place in C, so a conversion between two C buffers makes no PHP string.
* **2026-11-14**: addition `plutovg_surface_put_alpha()`, the inverse of get_alpha: an A8 mask into a surface as 0xCC000000 words, in C.
