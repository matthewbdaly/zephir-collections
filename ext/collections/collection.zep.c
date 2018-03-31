
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
#include "kernel/string.h"


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
	zend_class_implements(collections_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(collections_collection_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
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
		zephir_array_fetch(&_0, &_2, offset, PH_NOISY, "collections/collection.zep", 75 TSRMLS_CC);
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

	zval *offset, offset_sub, items, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&items, &_0);
	zephir_array_unset(&items, offset, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("items"), &items);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get current item
 *
 * @return mixed
 */
PHP_METHOD(Collections_Collection, current) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "collections/collection.zep", 114 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

/**
 * Move counter to next item
 *
 * @return void
 */
PHP_METHOD(Collections_Collection, next) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, SL("position"), &_1);

}

/**
 * Get key for current item
 *
 * @return mixed
 */
PHP_METHOD(Collections_Collection, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "position");

}

/**
 * Move counter back to zero
 *
 * @return void
 */
PHP_METHOD(Collections_Collection, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_0);

}

/**
 * Is current item valid?
 *
 * @return boolean
 */
PHP_METHOD(Collections_Collection, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Serialize collection to JSON
 *
 * @return string
 */
PHP_METHOD(Collections_Collection, jsonSerialize) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_json_encode(return_value, &_0, 0 );
	return;

}

/**
 * Convert collection to JSON
 *
 * @return string
 */
PHP_METHOD(Collections_Collection, toJson) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "jsonserialize", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convert collection to array
 *
 * @return array
 */
PHP_METHOD(Collections_Collection, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "items");

}

/**
 * Map operation
 *
 * @param mixed callback The callback to use.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, map) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, collections_collection_ce);
	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", NULL, 2, callback, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Filter operation
 *
 * @param mixed callback The callback to use.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, filter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, collections_collection_ce);
	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 3, &_0, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reverse filter operation
 *
 * @param mixed callback The callback to use.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, reject) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, foundItems, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&foundItems);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&foundItems, "array_filter", NULL, 3, &_0, callback);
	zephir_check_call_status();
	object_init_ex(return_value, collections_collection_ce);
	zephir_read_property(&_1, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 4, &_1, &foundItems);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reduce operation
 *
 * @param mixed callback The callback to use.
 * @param mixed initial  The initial value.
 * @return mixed
 */
PHP_METHOD(Collections_Collection, reduce) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, *initial = NULL, initial_sub, accumulator, item, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&initial_sub);
	ZVAL_UNDEF(&accumulator);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &initial);

	if (!initial) {
		initial = &initial_sub;
		ZEPHIR_INIT_VAR(initial);
		ZVAL_LONG(initial, 0);
	}


	ZEPHIR_CPY_WRT(&accumulator, initial);
	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "collections/collection.zep", 235);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_2$$3, callback, NULL, 0, &accumulator, &item);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&accumulator, &_2$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&accumulator);

}

/**
 * Pluck a single field
 *
 * @param mixed name Name of field to pluck.
 * @return mixed
 */
PHP_METHOD(Collections_Collection, pluck) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);



	RETURN_BOOL(1);

}

/**
 * Apply callback to each item in the collection
 *
 * @param mixed callback The callback to use.
 * @return void
 */
PHP_METHOD(Collections_Collection, each) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, item, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "collections/collection.zep", 261);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, 0, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * Push item to end of collection
 *
 * @param mixed item Item to push.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, items, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&items, &_0);
	ZEPHIR_MAKE_REF(&items);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 5, &items, item);
	ZEPHIR_UNREF(&items);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("items"), &items);
	object_init_ex(return_value, collections_collection_ce);
	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Pop item from end of collection
 *
 * @return mixed
 */
PHP_METHOD(Collections_Collection, pop) {

	zval items, _0, response;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&items, &_0);
	ZEPHIR_MAKE_REF(&items);
	ZEPHIR_CALL_FUNCTION(&response, "array_pop", NULL, 6, &items);
	ZEPHIR_UNREF(&items);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("items"), &items);
	RETURN_CCTOR(&response);

}

/**
 * Push item to start of collection
 *
 * @param mixed item Item to push.
 * @return Collection
 */
PHP_METHOD(Collections_Collection, unshift) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, items, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&items, &_0);
	ZEPHIR_MAKE_REF(&items);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 7, &items, item);
	ZEPHIR_UNREF(&items);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("items"), &items);
	object_init_ex(return_value, collections_collection_ce);
	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Pop item from start of collection
 *
 * @return mixed
 */
PHP_METHOD(Collections_Collection, shift) {

	zval items, _0, response;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&items, &_0);
	ZEPHIR_MAKE_REF(&items);
	ZEPHIR_CALL_FUNCTION(&response, "array_shift", NULL, 8, &items);
	ZEPHIR_UNREF(&items);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("items"), &items);
	RETURN_CCTOR(&response);

}

