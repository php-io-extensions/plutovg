# Agent guidance — php-io-extensions/plutovg

1. **Read the design spec first:** [`docs/superpowers/specs/2026-11-13-plutovg-design.md`](docs/superpowers/specs/2026-11-13-plutovg-design.md). Its "Names and translations" lists every translation; there are no others.
2. **Bindings are 1:1 at PlutoVG 1.3.3** (tag `v1.3.3`, commit `bbd91f0d06a71491691b36330f29dffa4af87ccf`): every `PLUTOVG_API` function in `plutovg.h`, plus `plutovg_surface_get_alpha`, `plutovg_surface_get_data_address` and `plutovg_surface_create_for_address`. Function, struct, enum and constant names are the C names (classes drop `_t`). No defaults, no composites.
3. **Upstream is copied unchanged** into `lib/plutovg/` (`include/`, `source/`, `LICENSE`, `README.md`). Never edit it. `config.m4` compiles exactly `plutovg_sources` from `meson.build` with the static build flags. A new PlutoVG only from a new upstream tag: replace `lib/plutovg/`, diff `plutovg.h`, update the bindings, tests, `PHP_PLUTOVG_UPSTREAM_COMMIT` and the version.
4. **The stub is the declaration.** Every `ZEND_FUNCTION` is written out by hand, never made by a macro; shared checks go through `src/runtime.c`.
5. **Memory PlutoVG draws into is kept alive by the handles that reach it** (each handle's keep list). Pixels otherwise cross as strings, copied in and out.
6. **Build.** `./install-macos.sh` into Homebrew `php@8.4` and `php@8.4-zts` (`zhp`). Pest: `php -d memory_limit=128M vendor/bin/pest` on both builds. After changing a check: `tools/sweep.php`. Gate a commit on the suite's exit code.
7. **Version** is `PHP_PLUTOVG_VERSION` in `php_plutovg.h`: 0.11.0, venusian/framework's 0.x line. `os-families`: linux, darwin.
