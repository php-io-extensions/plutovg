/*
 * plutovg: 1:1 bindings of PlutoVG 1.3.3. The library is compiled into this
 * extension. Function, struct and constant names stay the C names.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_plutovg.h"

#include "ext/standard/info.h"

#include "plutovg.h"
#include "runtime.h"
#include "../stubs/plutovg_core_arginfo.h"

void pv_path_minit(void);
void pv_surface_minit(void);
void pv_font_minit(void);
void pv_canvas_minit(void);

ZEND_FUNCTION(plutovg_version)
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(plutovg_version());
}

ZEND_FUNCTION(plutovg_version_string)
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_STRING(plutovg_version_string());
}

static PHP_MINIT_FUNCTION(plutovg)
{
#if defined(ZTS) && defined(COMPILE_DL_PLUTOVG)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	pv_runtime_minit(module_number);
	pv_path_minit();
	pv_surface_minit();
	pv_font_minit();
	pv_canvas_minit();
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(plutovg)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "plutovg support", "enabled");
	php_info_print_table_row(2, "Version", PHP_PLUTOVG_VERSION);
	php_info_print_table_row(2, "PlutoVG version", plutovg_version_string());
	php_info_print_table_row(2, "PlutoVG commit", PHP_PLUTOVG_UPSTREAM_COMMIT);
	php_info_print_table_end();
}

zend_module_entry plutovg_module_entry = {
	STANDARD_MODULE_HEADER,
	"plutovg",
	ext_functions,
	PHP_MINIT(plutovg),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(plutovg),
	PHP_PLUTOVG_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PLUTOVG
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(plutovg)
#endif
