
pkglib_LTLIBRARIES = glib.la

glib_la_CFLAGS = $(GLIB_CFLAGS)
glib_la_CPPFLAGS = -I$(top_srcdir)/include
glib_la_LDFLAGS = -no-undefined -module -avoid-version
glib_la_LIBADD = $(GLIB_LIBS)
glib_la_SOURCES = glib.c

if HAS_APR
pkglib_LTLIBRARIES += apr.la
apr_la_CFLAGS = $(GLIB_CFLAGS) $(APR_CFLAGS)
apr_la_CPPFLAGS = -I$(top_srcdir)/include
apr_la_LDFLAGS = -no-undefined -module -avoid-version
apr_la_LIBADD = $(APR_LIBS)
apr_la_SOURCES = apr.c
endif

if HAS_EINA
pkglib_LTLIBRARIES += eina.la
eina_la_CFLAGS = $(GLIB_CFLAGS) $(EINA_CFLAGS)
eina_la_CPPFLAGS = -I$(top_srcdir)/include
eina_la_LDFLAGS = -no-undefined -module -avoid-version
eina_la_LIBADD = $(EINA_LIBS)
eina_la_SOURCES = eina.c
endif
