
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(collections_0__closure) {

	ZEPHIR_REGISTER_CLASS(collections, 0__closure, collections, 0__closure, collections_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(collections_0__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_CALL_FUNCTION(&_0, "callback", NULL, 0, item);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));

}

