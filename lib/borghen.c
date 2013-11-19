
#include "borghen.h"

#include <stdlib.h>

#define BORGHEN_PLUGIN_DIR ((const gchar*)"BORGHEN_PLUGIN_DIR")

typedef struct _BorghenHash {
  BorghenBackendType type;
  BorghenObject hash;
  BorghenBoolean (*destory)(BorghenObject);
  void (*insert)(BorghenObject, BorghenObject, BorghenObject);
  void (*remove)(BorghenObject, BorghenObject);
  BorghenObject (*get)(BorghenObject, BorghenObject);
  BorghenBoolean (*contains)(BorghenObject, BorghenObject);
  BorghenSize (*size)(BorghenObject);
} _BorghenHash;

static BorghenString _borghen_modules[] = {
    "glib",
    "apr",
    "eina",
    "posix",
};
#define BORGHEN_N_MODULES 4
static GModule* _borghen_handles[BORGHEN_N_MODULES];

static BorghenBoolean _borghen_initialized = FALSE;
static BorghenBoolean _borghen_finalized   = FALSE;

static GModule* _borghen_module_open(BorghenString n)
{
  const gchar* bpd = g_getenv(BORGHEN_PLUGIN_DIR);
  GModule* g;
  gchar buf[PATH_MAX];

  if (bpd) {
      g_snprintf(buf, PATH_MAX, "%s%s%s", bpd, G_DIR_SEPARATOR_S, n);
      if ((g = g_module_open(buf, G_MODULE_BIND_MASK))) {
          return g;
      }
  }

  g_snprintf(buf, PATH_MAX, "%s%s%s", PKGLIBDIR, G_DIR_SEPARATOR_S, n);
  if ((g = g_module_open(buf, G_MODULE_BIND_MASK))) {
      return g;
  }

  return NULL;
}

BorghenBoolean borghen_initialize()
{
  if (_borghen_initialized) {
      return FALSE;
  }
  for (int i = 0; i < BORGHEN_N_MODULES; i++) {
      if ((_borghen_handles[i] = _borghen_module_open(_borghen_modules[i]))) {
          gpointer initialize;
          if (g_module_symbol(_borghen_handles[i], "borghen_backend_initialize", &initialize)) {
              ((void(*)()) initialize)();
          }
      }
  }
  return _borghen_initialized = TRUE;
}

BorghenBoolean borghen_initialized()
{
  return _borghen_initialized;
}

BorghenBoolean borghen_finalize()
{
  if (_borghen_finalized) {
      return FALSE;
  }
  for (int i = 0; i < BORGHEN_N_MODULES; i++) {
      if (_borghen_handles[i]) {
          gpointer finalize;
          if (g_module_symbol(_borghen_handles[i], "borghen_backend_finalize", &finalize)) {
              ((void(*)()) finalize)();
          }
      }
  }
  return _borghen_finalized = TRUE;
}

BorghenBoolean borghen_finalized()
{
  return _borghen_finalized;
}

BorghenHash borghen_new(BorghenBackendType t)
{
  if (!_borghen_handles[t]) {
      return NULL;
  }
  GModule* g = _borghen_handles[t];

  gpointer create;
  if (!g_module_symbol(g, "borghen_backend_create", &create)) {
      return NULL;
  }

  gpointer destroy;
  if (!g_module_symbol(g, "borghen_backend_destroy", &destroy)) {
      return NULL;
  }

  gpointer insert;
  if (!g_module_symbol(g, "borghen_backend_insert", &insert)) {
      return NULL;
  }

  gpointer remove;
  if (!g_module_symbol(g, "borghen_backend_remove", &remove)) {
      return NULL;
  }

  gpointer get;
  if (!g_module_symbol(g, "borghen_backend_get", &get)) {
      return NULL;
  }

  gpointer contains;
  if (!g_module_symbol(g, "borghen_backend_contains", &contains)) {
      return NULL;
  }

  gpointer size;
  if (!g_module_symbol(g, "borghen_backend_size", &size)) {
      return NULL;
  }

  BorghenHash h = malloc(sizeof(_BorghenHash));
  h->type = t;
  h->hash = ((BorghenObject(*)()) create)();
  h->destory = destroy;
  h->insert = insert;
  h->remove = remove;
  h->get = get;
  h->contains = contains;
  h->size = size;

  return h;
}

BorghenBoolean borghen_destory(BorghenHash h)
{
  gboolean result = h->destory(h->hash);
  free(h);
  return result;
}

void borghen_insert(BorghenHash h, BorghenObject key, BorghenObject value)
{
  h->insert(h->hash, key, value);
}

void borghen_remove(BorghenHash h, BorghenObject key)
{
  h->remove(h->hash, key);
}

BorghenObject borghen_get(BorghenHash h, BorghenObject key)
{
  return h->get(h->hash, key);
}

BorghenBoolean borghen_contains(BorghenHash h, BorghenObject key)
{
  return h->contains(h->hash, key);
}

BorghenSize borghen_size(BorghenHash h)
{
  return h->size(h->hash);
}
