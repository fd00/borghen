
#include "borghen.h"

void borghen_backend_initialize();
void borghen_backend_finalize();

BorghenObject borghen_backend_create();
BorghenBoolean borghen_backend_destroy(BorghenObject);
void borghen_backend_insert(BorghenObject, BorghenObject, BorghenObject);
void borghen_backend_remove(BorghenObject, BorghenObject);
BorghenObject borghen_backend_get(BorghenObject, BorghenObject);
BorghenBoolean borghen_backend_contains(BorghenObject, BorghenObject);
BorghenSize borghen_backend_size(BorghenObject);
