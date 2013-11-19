
#include "interface.h"

#include <Eina.h>

void borghen_backend_initialize()
{
  eina_init();
}
void borghen_backend_finalize()
{
  eina_shutdown();
}

BorghenObject borghen_backend_create()
{
  return eina_hash_string_djb2_new(NULL);
}

BorghenBoolean borghen_backend_destroy(BorghenObject hash)
{
  eina_hash_free(hash);
  return TRUE;
}

void borghen_backend_insert(BorghenObject hash, BorghenObject key, BorghenObject value)
{
  eina_hash_add(hash, key, value);
}

void borghen_backend_remove(BorghenObject hash, BorghenObject key)
{
  eina_hash_del_by_key(hash, key);
}

BorghenObject borghen_backend_get(BorghenObject hash, BorghenObject key)
{
  return eina_hash_find(hash, key);
}

BorghenBoolean borghen_backend_contains(BorghenObject hash, BorghenObject key)
{
  return (eina_hash_find(hash, key) != NULL);
}

BorghenSize borghen_backend_size(BorghenObject hash)
{
  return eina_hash_population(hash);
}
