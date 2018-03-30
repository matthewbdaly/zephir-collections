
extern zend_class_entry *collections_collection_ce;

ZEPHIR_INIT_CLASS(Collections_Collection);

PHP_METHOD(Collections_Collection, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_collections_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(collections_collection_method_entry) {
	PHP_ME(Collections_Collection, __construct, arginfo_collections_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
