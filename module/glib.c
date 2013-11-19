
#include "interface.h"

void borghen_backend_initialize()
{

}
void borghen_backend_finalize()
{

}

BorghenObject borghen_backend_create()
{
  return g_hash_table_new(NULL, NULL);
}

BorghenBoolean borghen_backend_destroy(BorghenObject hash)
{
  g_hash_table_destroy(hash);
  return TRUE;
}

void borghen_backend_insert(BorghenObject hash, BorghenObject key, BorghenObject value)
{
  g_hash_table_insert(hash, key, value);
}

void borghen_backend_remove(BorghenObject hash, BorghenObject key)
{
  g_hash_table_remove(hash, key);
}

BorghenObject borghen_backend_get(BorghenObject hash, BorghenObject key)
{
  return g_hash_table_lookup(hash, key);
}

BorghenBoolean borghen_backend_contains(BorghenObject hash, BorghenObject key)
{
  return g_hash_table_contains(hash, key);
}

BorghenSize borghen_backend_size(BorghenObject hash)
{
  return g_hash_table_size(hash);
}
