#if !defined VETTORE_H_
#define VETTORE_H_

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

extern int VectorFind(const Vector* v, const ElemType* e);

#endif // !defined VETTORE_H_
