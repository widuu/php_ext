dnl $Id$
dnl config.m4 for extension hello_word

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(hello_word, for hello_word support,
dnl Make sure that the comment is aligned:
dnl [  --with-hello_word             Include hello_word support])

dnl Otherwise use enable:

 PHP_ARG_ENABLE(hello_word, whether to enable hello_word support,
 Make sure that the comment is aligned:
[  --enable-hello_word           Enable hello_word support])

if test "$PHP_HELLO_WORD" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-hello_word -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/hello_word.h"  # you most likely want to change this
  dnl if test -r $PHP_HELLO_WORD/$SEARCH_FOR; then # path given as parameter
  dnl   HELLO_WORD_DIR=$PHP_HELLO_WORD
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for hello_word files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HELLO_WORD_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HELLO_WORD_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the hello_word distribution])
  dnl fi

  dnl # --with-hello_word -> add include path
  dnl PHP_ADD_INCLUDE($HELLO_WORD_DIR/include)

  dnl # --with-hello_word -> check for lib and symbol presence
  dnl LIBNAME=hello_word # you may want to change this
  dnl LIBSYMBOL=hello_word # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HELLO_WORD_DIR/$PHP_LIBDIR, HELLO_WORD_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HELLO_WORDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong hello_word lib version or lib not found])
  dnl ],[
  dnl   -L$HELLO_WORD_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HELLO_WORD_SHARED_LIBADD)

  PHP_NEW_EXTENSION(hello_word, hello_word.c, $ext_shared)
fi
