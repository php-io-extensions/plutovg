#ifndef PHP_PLUTOVG_H
#define PHP_PLUTOVG_H

extern zend_module_entry plutovg_module_entry;
#define phpext_plutovg_ptr &plutovg_module_entry

#define PHP_PLUTOVG_VERSION "0.11.0"

/* PlutoVG tag v1.3.3. A newer library lands only by replacing lib/plutovg/ from a published tag. */
#define PHP_PLUTOVG_UPSTREAM_COMMIT "bbd91f0d06a71491691b36330f29dffa4af87ccf"

#if defined(ZTS) && defined(COMPILE_DL_PLUTOVG)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
