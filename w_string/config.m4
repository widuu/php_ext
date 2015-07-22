dnl $Id$
dnl config.m4 for extension w_string

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(w_string, for w_string support,
dnl Make sure that the comment is aligned:
dnl [  --with-w_string             Include w_string support])

dnl Otherwise use enable:

 PHP_ARG_ENABLE(w_string, whether to enable w_string support,
 Make sure that the comment is aligned:
 [  --enable-w_string           Enable w_string support])

if test "$PHP_W_STRING" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-w_string -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/w_string.h"  # you most likely want to change this
  dnl if test -r $PHP_W_STRING/$SEARCH_FOR; then # path given as parameter
  dnl   W_STRING_DIR=$PHP_W_STRING
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for w_string files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       W_STRING_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$W_STRING_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the w_string distribution])
  dnl fi

  dnl # --with-w_string -> add include path
  dnl PHP_ADD_INCLUDE($W_STRING_DIR/include)

  dnl # --with-w_string -> check for lib and symbol presence
  dnl LIBNAME=w_string # you may want to change this
  dnl LIBSYMBOL=w_string # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $W_STRING_DIR/$PHP_LIBDIR, W_STRING_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_W_STRINGLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong w_string lib version or lib not found])
  dnl ],[
  dnl   -L$W_STRING_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(W_STRING_SHARED_LIBADD)

  PHP_NEW_EXTENSION(w_string, w_string.c, $ext_shared)
fi
