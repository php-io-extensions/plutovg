PHP_ARG_ENABLE([plutovg],
  [whether to enable plutovg support],
  [AS_HELP_STRING([--enable-plutovg], [Enable the PlutoVG 1.3.3 bindings])],
  [no])

if test "$PHP_PLUTOVG" != "no"; then
  dnl The binding's own C.
  plutovg_glue="src/plutovg.c src/runtime.c src/path.c src/surface.c src/font.c src/canvas.c"

  dnl PlutoVG 1.3.3 as its meson.build lists it. lib/plutovg is never edited.
  plutovg_lib=" \
    lib/plutovg/source/plutovg-blend.c \
    lib/plutovg/source/plutovg-canvas.c \
    lib/plutovg/source/plutovg-font.c \
    lib/plutovg/source/plutovg-matrix.c \
    lib/plutovg/source/plutovg-paint.c \
    lib/plutovg/source/plutovg-path.c \
    lib/plutovg/source/plutovg-rasterize.c \
    lib/plutovg/source/plutovg-surface.c \
    lib/plutovg/source/plutovg-ft-math.c \
    lib/plutovg/source/plutovg-ft-raster.c \
    lib/plutovg/source/plutovg-ft-stroker.c \
"

  dnl Static build flags from meson: PLUTOVG_BUILD + PLUTOVG_BUILD_STATIC (no visibility attribute).
  dnl HAVE_THREADS_H gives the font-face cache its C11 mutex; macOS has no <threads.h>, so there the
  dnl cache runs unlocked, exactly as an upstream macOS build does.
  plutovg_cflags="-std=gnu17 -fvisibility=hidden -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -DPLUTOVG_BUILD -DPLUTOVG_BUILD_STATIC -Wno-sign-compare -Wno-unused-function"
  AC_CHECK_HEADER([threads.h], [plutovg_cflags="$plutovg_cflags -DHAVE_THREADS_H"])

  PHP_NEW_EXTENSION([plutovg],
    [$plutovg_glue $plutovg_lib],
    [$ext_shared],,
    [$plutovg_cflags -I$ext_srcdir/src -I$ext_srcdir/lib/plutovg/include])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
  PHP_ADD_BUILD_DIR([$ext_builddir/lib/plutovg/source])

  dnl Export get_module only (ext-pixman's lesson): no other copy of PlutoVG in the
  dnl process (lunasvg, plutosvg) can capture this binding's calls, nor this one theirs.
  case $host_os in
    darwin*)
      PLUTOVG_SHARED_LIBADD="-Wl,-exported_symbol,_get_module"
      ;;
    *)
      PLUTOVG_SHARED_LIBADD="-Wl,--version-script=$ext_srcdir/src/plutovg.map"
      PHP_ADD_LIBRARY([pthread],, [PLUTOVG_SHARED_LIBADD])
      PHP_ADD_LIBRARY([m],, [PLUTOVG_SHARED_LIBADD])
      ;;
  esac
  PHP_SUBST([PLUTOVG_SHARED_LIBADD])
fi
