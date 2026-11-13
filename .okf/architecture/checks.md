---
type: Architecture
title: Safety checks
description: Inputs PlutoVG 1.3.3 trusts that the binding refuses, keep lists, symbol export.
resource: src/runtime.c
tags: [plutovg, security]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-13T00:00:00Z }
---

# Safety checks

- Enums range-checked (the operator indexes a function-pointer table).
- Self-add of a path (and of the canvas path) refused: PlutoVG copies from the array it grows.
- NaN arc angles, reserves past 2^24 elements, negative/NaN dashes and patterns over 2^22 dashes (also at stroke time) refused.
- Iterators refuse stepping at the end or after their path changed; text `-1` lengths are resolved inside the string.
- `create_for_data` draws into a binding-owned string copy; every handle reaching it keeps it alive (keep lists).
- Fonts and images are trusted input (stb_truetype / stb_image).
- Only `get_module` is exported.
- `tools/sweep.php`: every function × five argument sets, one process each.
