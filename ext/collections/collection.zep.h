
extern zend_class_entry *collections_collection_ce;

ZEPHIR_INIT_CLASS(Collections_Collection);

PHP_METHOD(Collections_Collection, __construct);
PHP_METHOD(Collections_Collection, make);
PHP_METHOD(Collections_Collection, count);
PHP_METHOD(Collections_Collection, offsetExists);
PHP_METHOD(Collections_Collection, offsetGet);
PHP_METHOD(Collections_Collection, offsetSet);
PHP_METHOD(Collections_Collection, offsetUnset);
PHP_METHOD(Collections_Collection, current);
PHP_METHOD(Collections_Collection, next);
PHP_METHOD(Collections_Collection, key);
PHP_METHOD(Collections_Collection, rewind);
PHP_METHOD(Collections_Collection, valid);
PHP_METHOD(Collections_Collection, jsonSerialize);
PHP_METHOD(Collections_Collection, toJson);
PHP_METHOD(Collections_Collection, toArray);
PHP_METHOD(Collections_Collection, map);
PHP_METHOD(Collections_Collection, filter);
PHP_METHOD(Collections_Collection, reject);
PHP_METHOD(Collections_Collection, reduce);
PHP_METHOD(Collections_Collection, each);
PHP_METHOD(Collections_Collection, push);
PHP_METHOD(Collections_Collection, pop);
PHP_METHOD(Collections_Collection, unshift);
PHP_METHOD(Collections_Collection, shift);

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_make, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_map, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_reject, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_reduce, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, initial)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_each, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_push, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection_unshift, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(collections_collection_method_entry) {
	PHP_ME(Collections_Collection, __construct, arginfo_collections_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Collections_Collection, make, arginfo_collections_collection_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Collections_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetExists, arginfo_collections_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetGet, arginfo_collections_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetSet, arginfo_collections_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetUnset, arginfo_collections_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, toJson, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, map, arginfo_collections_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, filter, arginfo_collections_collection_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, reject, arginfo_collections_collection_reject, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, reduce, arginfo_collections_collection_reduce, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, each, arginfo_collections_collection_each, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, push, arginfo_collections_collection_push, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, pop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, unshift, arginfo_collections_collection_unshift, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, shift, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
