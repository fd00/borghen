AC_PREREQ(2.59)
AC_INIT([borghen], [0.1.0])
AC_PROG_CC
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign])

AM_PROG_CC_C_O
LT_INIT([disable-static])

PKG_CHECK_MODULES([GLIB], [glib-2.0 gmodule-2.0])

PKG_CHECK_MODULES([APR], [apr-1], [use_apr=true])
AM_CONDITIONAL(USE_APR, test x$use_apr = xtrue)
PKG_CHECK_MODULES([EINA], [eina], [use_eina=true])
AM_CONDITIONAL(USE_EINA, test x$use_eina = xtrue)

AC_CONFIG_FILES(Makefile
                borghen.pc
                include/Makefile
                lib/Makefile
                module/Makefile
                test/Makefile)
AC_OUTPUT
