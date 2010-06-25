dnl $Id$
dnl config.m4 for extension xhrupload

PHP_ARG_ENABLE(xhrupload, [whether to enable xhrupload and time advanced functions],
[  --enable-xhrupload       Enable support for xhrupload and time adv. functions])

if test "$PHP_XHRUPLOAD" != "no"; then
  AC_DEFINE(HAVE_XHRUPLOAD,1,[ ])
  PHP_NEW_EXTENSION(xhrupload, xhrupload.c, $ext_shared)
fi

