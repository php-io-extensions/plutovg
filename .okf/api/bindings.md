---
type: API
title: Bindings
description: What ext-plutovg binds, under which names, and the two additions.
resource: docs/superpowers/specs/2026-11-13-plutovg-design.md
tags: [plutovg, api]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-13T00:00:00Z }
---

# Bindings

- All 212 `PLUTOVG_API` functions of `lib/plutovg/include/plutovg.h`, C names, C parameter order.
- Value structs: `plutovg_point`, `plutovg_rect`, `plutovg_matrix`, `plutovg_color`, `plutovg_gradient_stop`, `plutovg_path_element(_header)`.
- Handles (one reference each): `plutovg_surface`, `plutovg_canvas`, `plutovg_paint`, `plutovg_path`, `plutovg_font_face`, `plutovg_font_face_cache`. Iterators: `plutovg_path_iterator`, `plutovg_text_iterator`.
- Additions: `plutovg_surface_get_alpha` (packed alpha plane: a white fill's a8 coverage), `plutovg_surface_get_data_address`, `plutovg_surface_create_for_address` (draw into memory another extension owns; owner kept alive).
- Every translation is in the design spec's "Names and translations"; there are no others.
