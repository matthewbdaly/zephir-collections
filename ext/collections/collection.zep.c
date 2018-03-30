
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Collections_Collection) {

	ZEPHIR_REGISTER_CLASS(Collections, Collection, collections, collection, collections_collection_method_entry, 0);

	/**
	 * Items
	 *
	 * @var array
	 */
	zend_declare_property_null(collections_collection_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Position
	 *
	 * @var integer
	 */
	zend_declare_property_long(collections_collection_ce, SL("position"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array items Items to collect.
 * @return void
 */
PHP_METHOD(Collections_Collection, __construct) {

	zval *items_param = NULL;
	zval items;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items_param);

	if (!items_param) {
		ZEPHIR_INIT_VAR(&items);
		array_init(&items);
	} else {
		zephir_get_arrval(&items, items_param);
	}


	zephir_update_property_zval(this_ptr, SL("items"), &items);
	ZEPHIR_MM_RESTORE();

}

