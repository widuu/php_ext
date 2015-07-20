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
  | Author:     <widuu>admin@widuu.com                                       |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_WIDUU_H
#define PHP_WIDUU_H

extern zend_module_entry widuu_module_entry;
#define phpext_widuu_ptr &widuu_module_entry

#define PHP_WIDUU_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_WIDUU_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_WIDUU_API __attribute__ ((visibility("default")))
#else
#	define PHP_WIDUU_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(widuu);
PHP_MSHUTDOWN_FUNCTION(widuu);
PHP_MINFO_FUNCTION(widuu);

PHP_FUNCTION(read_ini);	


ZEND_BEGIN_MODULE_GLOBALS(widuu)
      zend_bool enable;
	long  size;
	char *name;
ZEND_END_MODULE_GLOBALS(widuu)


#ifdef ZTS
#define WIDUU_G(v) TSRMG(widuu_globals_id, zend_widuu_globals *, v)
#else
#define WIDUU_G(v) (widuu_globals.v)
#endif

#endif	/* PHP_WIDUU_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
