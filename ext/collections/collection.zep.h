
extern zend_class_entry *collections_collection_ce;

ZEPHIR_INIT_CLASS(Collections_Collection);

PHP_METHOD(Collections_Collection, __construct);
PHP_METHOD(Collections_Collection, make);
PHP_METHOD(Collections_Collection, count);
PHP_METHOD(Collections_Collection, offsetExists);
PHP_METHOD(Collections_Collection, offsetGet);
PHP_METHOD(Collections_Collection, offsetSet);
PHP_METHOD(Collections_Collection, offsetUnset);

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

ZEPHIR_INIT_FUNCS(collections_collection_method_entry) {
	PHP_ME(Collections_Collection, __construct, arginfo_collections_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Collections_Collection, make, arginfo_collections_collection_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Collections_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetExists, arginfo_collections_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetGet, arginfo_collections_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetSet, arginfo_collections_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Collections_Collection, offsetUnset, arginfo_collections_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
