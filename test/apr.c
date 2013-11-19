
#include "borghen.h"

void test(void)
{
  g_assert(!borghen_initialized());
  borghen_initialize();
  g_assert(borghen_initialized());
  BorghenHash h = borghen_new(BORGHEN_BACKEND_APR);
  g_assert(h);
  g_assert(borghen_size(h) == 0);
  g_assert(borghen_get(h, "key1") == NULL);
  borghen_insert(h, "key1", "value1");
  g_assert(borghen_size(h) == 1);
  g_assert_cmpstr(borghen_get(h, "key1"), ==, "value1");
  borghen_insert(h, "key2", "value2");
  g_assert(borghen_size(h) == 2);
  g_assert_cmpstr(borghen_get(h, "key2"), ==, "value2");
  borghen_remove(h, "key1");
  g_assert(borghen_get(h, "key1") == NULL);
  g_assert(borghen_size(h) == 1);
  g_assert(borghen_destory(h));
  g_assert(!borghen_finalized());
  borghen_finalize();
  g_assert(borghen_finalized());
}

int main(int argc, char** argv)
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/apr/test", test);
  g_test_run();
}
