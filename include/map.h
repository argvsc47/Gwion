#ifndef __MAP
#define __MAP
#include "defs.h"
#include <symbol.h>

typedef m_uint vtype;
#include "map_private.h"
typedef struct Vector_ * Vector;
typedef struct Map_    * Map;

extern Vector new_vector();
//extern Vector new_vector_fixed(const vtype len);
extern void   vector_init(Vector v);
extern Vector vector_copy(Vector v);
extern void vector_copy2(Vector v, Vector ret);
extern m_int vector_find(Vector vector, vtype data);
inline void vector_set(Vector v, const vtype i, vtype arg) {
  v->ptr[i + OFFSET] = arg;
}
inline vtype vector_front(Vector v) {
  return v->ptr[0] ? v->ptr[0 + OFFSET] : 0;
}

inline vtype vector_at(Vector v, const vtype i) {
  return (i >= v->ptr[0]) ? 0 : v->ptr[i + OFFSET];
}

inline vtype vector_back(Vector v) {
  return v->ptr[v->ptr[0] + OFFSET - 1];
}

inline vtype vector_size(Vector v) {
  return v->ptr[0];
}
extern void vector_add(Vector vector, vtype data);
extern void vector_rem(Vector vector, const vtype index);
extern vtype vector_pop(Vector vector);
extern void vector_clear(Vector vector);
extern void free_vector(Vector vector);
extern void vector_release(Vector vector);

extern Map   new_map();
extern void  map_init();
extern vtype map_get(Map map, vtype key);
extern vtype map_at(Map map, const vtype index);
//extern vtype map_key(Map map, const vtype index);
extern void  map_set(Map map, vtype key, vtype ptr);
extern void  map_remove(Map map, vtype key);
extern void  map_commit(Map map, Map commit);
//extern void  map_rollback(Map map, void (*_free)(vtype));
extern vtype map_size(Map map);
extern void  free_map(Map map);
extern void  map_release(Map map);
extern void  map_clear(Map map);

extern Scope  new_scope();
extern void   scope_init(Scope v);
extern Vector scope_get(Scope a);
extern vtype  scope_lookup0(Scope scope, S_Symbol xid);
extern vtype  scope_lookup1(Scope scope, S_Symbol xid);
extern vtype  scope_lookup2(Scope scope, S_Symbol xid);
extern void   scope_add(Scope scope, S_Symbol xid, vtype value);
extern void   scope_commit(Scope scope);
//extern void   scope_rollback(Scope scope, void (*_free)(vtype arg));
extern void   scope_push(Scope scope);
extern void   scope_pop(Scope scope);
extern void   free_scope(Scope a);
extern void   scope_release(Scope a);
#endif
