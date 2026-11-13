---
type: Runbook
title: Build, install, test
description: Building ext-plutovg on macOS and Debian, running Pest and the crash sweep.
resource: install-macos.sh
tags: [plutovg, build]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-13T00:00:00Z }
---

# Build, install, test

1. macOS: `./install-macos.sh` builds in a temp copy for Homebrew `php@8.4` and `php@8.4-zts`, signs ad hoc, writes `30-plutovg.ini`.
2. Debian/Pi: `./install-debian-trixie.sh` (needs `php8.4-dev`, nothing else).
3. Stubs: `php /opt/homebrew/opt/php@8.4/lib/php/build/gen_stub.php stubs` after any stub edit; commit stubs and arginfo together.
4. Pest on both builds: `php -d memory_limit=128M vendor/bin/pest`. Font tests need Arial (macOS) or DejaVu Sans (Debian), else skip.
5. After changing argument checks: `php -d memory_limit=256M tools/sweep.php` (every function but `create_for_address`, × five argument sets).
