#if !defined VETTORE_H_
#define VETTORE_H_

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

extern void VectorSort(Vector* v);

#endif // !defined VETTORE_H_
