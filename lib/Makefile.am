
lib_LTLIBRARIES = libborghen.la
libborghen_la_CFLAGS = $(GLIB_CFLAGS)
libborghen_la_CPPFLAGS = -I$(top_builddir) -I$(top_srcdir)/include -DPKGLIBDIR=\"$(pkglibdir)\"
libborghen_la_LDFLAGS = -no-undefined
libborghen_la_LIBADD = $(GLIB_LIBS)
libborghen_la_SOURCES = borghen.c
