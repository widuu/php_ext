/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_w_string.h"

/* True global resources - no need for thread safety here */
static int le_w_string;

/* {{{ w_string_functions[]
 *
 * Every user visible function must have an entry in w_string_functions[].
 */
const zend_function_entry w_string_functions[] = {
	PHP_FE( return_string , NULL )
	PHP_FE_END	/* Must be the last line in w_string_functions[] */
};
/* }}} */

/* {{{ w_string_module_entry
 */
zend_module_entry w_string_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"w_string",
	w_string_functions,
	PHP_MINIT(w_string),
	PHP_MSHUTDOWN(w_string),
	NULL,		/* Replace with NULL if there's nothing to do at request start */
	NULL,	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(w_string),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_W_STRING_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_W_STRING
ZEND_GET_MODULE(w_string)
#endif


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(w_string)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(w_string)
{
	return SUCCESS;
}
/* }}} */

/*{{{ PHP_FUNCTION(return_string) */
PHP_FUNCTION(return_string){
	const char* name = "website:http://www.widuu.com";
	// Z_STRVAL_P(return_value)= estrndup( name,strlen(name));
	// Z_STRLEN_P(return_value) = strlen(name);
	// Z_TYPE_P(return_value) = IS_STRING;

	return_value->value.str.val = estrndup( name,strlen(name));
	return_value->value.str.len = strlen(name);
	return_value->type = IS_STRING;
}
/*}}}*/

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(w_string)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "w_string support", "enabled");
	php_info_print_table_row(2 , "author" , "widuu <admin@widuu.com>");
	php_info_print_table_end();
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
