
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "matthewbdaly.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *matthewbdaly_collections_collection_ce;

ZEND_DECLARE_MODULE_GLOBALS(matthewbdaly)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(matthewbdaly)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Matthewbdaly_Collections_Collection);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(matthewbdaly)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_matthewbdaly_globals *matthewbdaly_globals TSRMLS_DC)
{
	matthewbdaly_globals->initialized = 0;

	/* Memory options */
	matthewbdaly_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	matthewbdaly_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	matthewbdaly_globals->cache_enabled = 1;

	/* Recursive Lock */
	matthewbdaly_globals->recursive_lock = 0;

	/* Static cache */
	memset(matthewbdaly_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_matthewbdaly_globals *matthewbdaly_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(matthewbdaly)
{

	zend_matthewbdaly_globals *matthewbdaly_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	matthewbdaly_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(matthewbdaly_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(matthewbdaly_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(matthewbdaly)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(matthewbdaly)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_MATTHEWBDALY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MATTHEWBDALY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_MATTHEWBDALY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_MATTHEWBDALY_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_MATTHEWBDALY_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(matthewbdaly)
{
	php_zephir_init_globals(matthewbdaly_globals TSRMLS_CC);
	php_zephir_init_module_globals(matthewbdaly_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(matthewbdaly)
{

}


zend_function_entry php_matthewbdaly_functions[] = {
ZEND_FE_END

};

zend_module_entry matthewbdaly_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_MATTHEWBDALY_EXTNAME,
	php_matthewbdaly_functions,
	PHP_MINIT(matthewbdaly),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(matthewbdaly),
#else
	NULL,
#endif
	PHP_RINIT(matthewbdaly),
	PHP_RSHUTDOWN(matthewbdaly),
	PHP_MINFO(matthewbdaly),
	PHP_MATTHEWBDALY_VERSION,
	ZEND_MODULE_GLOBALS(matthewbdaly),
	PHP_GINIT(matthewbdaly),
	PHP_GSHUTDOWN(matthewbdaly),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_MATTHEWBDALY
ZEND_GET_MODULE(matthewbdaly)
#endif
