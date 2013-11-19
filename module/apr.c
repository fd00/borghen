
#include "interface.h"

#include <apr_hash.h>

static apr_pool_t* pool;

void borghen_backend_initialize()
{
  apr_initialize();
  apr_pool_create(&pool, NULL);
}
void borghen_backend_finalize()
{
  apr_pool_destroy(pool);
  apr_terminate();
}

BorghenObject borghen_backend_create()
{
  return apr_hash_make(pool);
}

BorghenBoolean borghen_backend_destroy(BorghenObject hash)
{
  apr_hash_clear(hash);
  return TRUE;
}

void borghen_backend_insert(BorghenObject hash, BorghenObject key, BorghenObject value)
{
  apr_hash_set(hash, key, APR_HASH_KEY_STRING, value);
}

void borghen_backend_remove(BorghenObject hash, BorghenObject key)
{
  apr_hash_set(hash, key, APR_HASH_KEY_STRING, NULL);
}

BorghenObject borghen_backend_get(BorghenObject hash, BorghenObject key)
{
  return apr_hash_get(hash, key, APR_HASH_KEY_STRING);
}

BorghenBoolean borghen_backend_contains(BorghenObject hash, BorghenObject key)
{
  return (apr_hash_get(hash, key, APR_HASH_KEY_STRING) != NULL);
}

BorghenSize borghen_backend_size(BorghenObject hash)
{
  return apr_hash_count(hash);
}
