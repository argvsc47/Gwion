#ifndef __GWIONDATA
#define __GWIONDATA
typedef struct GwionData_ {
  struct Map_ freearg;
  struct Map_ id;
  MUTEX_TYPE mutex;
  struct Vector_ child;
  struct Vector_ reserved;
  struct Map_ pass_map;
  struct Vector_ pass;
  struct Gwion_ *base;
} GwionData;

ANN GwionData* new_gwiondata(MemPool);
ANN void free_gwiondata(MemPool, GwionData*);
#endif
