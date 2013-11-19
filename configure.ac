AC_PREREQ(2.59)
AC_INIT([borghen], [0.0.20131120])
AC_PROG_CC
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign])

AM_PROG_CC_C_O
LT_INIT([disable-static])

PKG_CHECK_MODULES([GLIB], [glib-2.0 gmodule-2.0])

PKG_CHECK_MODULES([APR], [apr-1], [has_apr=true])
AM_CONDITIONAL(HAS_APR, test x$has_apr = xtrue)
PKG_CHECK_MODULES([EINA], [eina], [has_eina=true])
AM_CONDITIONAL(HAS_EINA, test x$has_eina = xtrue)

AC_CONFIG_FILES(Makefile
                include/Makefile
                lib/Makefile
                module/Makefile
                test/Makefile)
AC_OUTPUT
