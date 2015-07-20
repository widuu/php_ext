
 PHP_ARG_ENABLE(widuu, whether to enable widuu support,
Make sure that the comment is aligned:
 [  --enable-widuu           Enable widuu support])
if test "$PHP_WIDUU" != "no"; then
  PHP_NEW_EXTENSION(widuu, widuu.c, $ext_shared)
fi
