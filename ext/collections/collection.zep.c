
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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

	zend_class_implements(collections_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(collections_collection_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
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

/**
 * Create collection
 *
 * @param array items Items to collect.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, make) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL;
	zval items;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &items_param);

	zephir_get_arrval(&items, items_param);


	object_init_ex(return_value, collections_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &items);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return count of items
 *
 * @return integer
 */
PHP_METHOD(Collections_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Does item exist?
 *
 * @param mixed offset The offset.
 * @return boolean
 */
PHP_METHOD(Collections_Collection, offsetExists) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, offset));

}

/**
 * Get offset
 *
 * @param mixed offset The offset.
 * @return mixed
 */
PHP_METHOD(Collections_Collection, offsetGet) {

	zval *offset, offset_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, offset)) {
		zephir_read_property(&_2, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, offset, PH_NOISY, "collections/collection.zep", 73 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Set offset
 *
 * @param mixed offset The offset.
 * @param mixed value  The value to set.
 * @return void
 */
PHP_METHOD(Collections_Collection, offsetSet) {

	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &offset, &value);



	if (Z_TYPE_P(offset) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("items"), value TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("items"), offset, value TSRMLS_CC);
	}

}

/**
 * Unset offset
 *
 * @param mixed offset The offset.
 * @return void
 */
PHP_METHOD(Collections_Collection, offsetUnset) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, offset, PH_SEPARATE);

}

