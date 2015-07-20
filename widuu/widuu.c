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
  #include "php_ini.h"
#include "ext/standard/info.h"
#include "php_widuu.h"
 #include <zend_ini.h>


ZEND_DECLARE_MODULE_GLOBALS(widuu)



const zend_function_entry widuu_functions[] = {
	PHP_FE(read_ini,	NULL)		
	PHP_FE_END	
};

zend_module_entry widuu_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"widuu",
	widuu_functions,
	PHP_MINIT(widuu),
	PHP_MSHUTDOWN(widuu),
	NULL,		
	NULL,		
	PHP_MINFO(widuu),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_WIDUU_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_WIDUU
ZEND_GET_MODULE(widuu)
#endif


PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("widuu.enable",      "1", PHP_INI_ALL, OnUpdateBool, enable, zend_widuu_globals, widuu_globals)
    STD_PHP_INI_ENTRY("widuu.size",      "42", PHP_INI_ALL, OnUpdateLong, size, zend_widuu_globals, widuu_globals)
    STD_PHP_INI_ENTRY("widuu.name", "widuu", PHP_INI_ALL, OnUpdateString, name, zend_widuu_globals, widuu_globals)
PHP_INI_END()


PHP_MINIT_FUNCTION(widuu)
{

	REGISTER_INI_ENTRIES();
	
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(widuu)
{

	UNREGISTER_INI_ENTRIES();

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(widuu)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "widuu support", "enabled");
	php_info_print_table_row(2 , "author", "widuu <admin@widuu.com>" );
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

PHP_FUNCTION(read_ini){
	char *str,*varname;
	int str_len;

	if( zend_parse_parameters( ZEND_NUM_ARGS() TSRMLS_CC, "s" ,&varname,&str_len) == FAILURE){
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "don't exists parameter");
		return;
	}
	str = zend_ini_string(  varname, str_len+1, 0 );

	if (!str) {
		RETURN_FALSE;
	}

	RETURN_STRING( str , 1);
	// str = zend_ini_string("widuu.name", sizeof("widuu.name"), 0);
	//  long maxwait = zend_ini_long("widuu.size",  sizeof("widuu.size"), 0);
	// if (str == NULL) {
	// 	php_error_docref("widuu.size", E_WARNING, "config not exists");
	// }
	// printf("%s\n",str );
	// printf("%d\n", maxwait );
	// if (name != NULL){
	// 	printf("%s\n", name);
	// }
	// RETURN_FALSE;
	
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
