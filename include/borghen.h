#if !defined(BORGHEN_H)
#define BORGHEN_H

#include <gmodule.h>

typedef enum {
  BORGHEN_BACKEND_GLIB    = 0,
  BORGHEN_BACKEND_APR     = 1,
  BORGHEN_BACKEND_EINA    = 2,
  BORGHEN_BACKEND_POSIX   = 3,
} BorghenBackendType;

typedef gpointer             BorghenObject;
typedef gboolean             BorghenBoolean;
typedef guint                BorghenSize;
typedef gchar*               BorghenString;
typedef GModule*             BorghenModule;
typedef struct _BorghenHash *BorghenHash;

BorghenBoolean borghen_initialize();
BorghenBoolean borghen_initialized();
BorghenBoolean borghen_finalize();
BorghenBoolean borghen_finalized();

BorghenHash    borghen_new(BorghenBackendType t);
BorghenBoolean borghen_destory(BorghenHash h);

void           borghen_insert(BorghenHash h, BorghenObject key, BorghenObject value);
void           borghen_remove(BorghenHash h, BorghenObject key);

BorghenObject  borghen_get(BorghenHash h, BorghenObject key);
BorghenBoolean borghen_contains(BorghenHash h, BorghenObject key);
BorghenSize    borghen_size(BorghenHash h);

#endif
