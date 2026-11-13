---
okf_version: "0.2"
---

# ext-plutovg

1:1 PHP bindings of PlutoVG 1.3.3 (vendored, unchanged), a small C 2D vector graphics library. Version 0.11.0. Linux, macOS. PHP 8.4 NTS + ZTS.

# API

* [Bindings](api/bindings.md) — 212 functions, three additions, value-struct and handle classes, constants.

# Architecture

* [Safety checks](architecture/checks.md) — the inputs PlutoVG trusts and the binding refuses, keep lists, symbol export.

# Runbooks

* [Build, install, test](runbooks/build.md) — Mac NTS/ZTS, Debian, the crash sweep.
