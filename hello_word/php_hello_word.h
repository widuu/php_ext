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

#ifndef PHP_HELLO_WORD_H
#define PHP_HELLO_WORD_H

extern zend_module_entry hello_word_module_entry;
#define phpext_hello_word_ptr &hello_word_module_entry

#define PHP_HELLO_WORD_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_HELLO_WORD_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_HELLO_WORD_API __attribute__ ((visibility("default")))
#else
#	define PHP_HELLO_WORD_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(hello_word);
PHP_MSHUTDOWN_FUNCTION(hello_word);
PHP_MINFO_FUNCTION(hello_word);

// echo hello php function 
PHP_FUNCTION(echo_hello_php);

// return hello php function
PHP_FUNCTION(return_hello_php);

#ifdef ZTS
#define HELLO_WORD_G(v) TSRMG(hello_word_globals_id, zend_hello_word_globals *, v)
#else
#define HELLO_WORD_G(v) (hello_word_globals.v)
#endif

#endif	/* PHP_HELLO_WORD_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
