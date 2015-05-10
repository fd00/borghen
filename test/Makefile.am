
TEST_PROGS = glib
check_PROGRAMS = $(TEST_PROGS)

glib_CFLAGS = $(GLIB_CFLAGS)
glib_CPPFLAGS = -I$(top_srcdir)/include
glib_LDADD = $(top_builddir)/lib/libborghen.la
glib_SOURCES = glib.c

if USE_APR
TEST_PROGS += apr
apr_CFLAGS = $(GLIB_CFLAGS) $(APR_CFLAGS)
apr_CPPFLAGS = -I$(top_srcdir)/include
apr_LDADD = $(top_builddir)/lib/libborghen.la
apr_SOURCES = apr.c
endif

if USE_EINA
TEST_PROGS += eina
eina_CFLAGS = $(GLIB_CFLAGS) $(EINA_CFLAGS)
eina_CPPFLAGS = -I$(top_srcdir)/include
eina_LDADD = $(top_builddir)/lib/libborghen.la
eina_SOURCES = eina.c
endif

check: $(TEST_PROGS)
	BORGHEN_PLUGIN_DIR=$(top_builddir)/module gtester --verbose $(TEST_PROGS)
