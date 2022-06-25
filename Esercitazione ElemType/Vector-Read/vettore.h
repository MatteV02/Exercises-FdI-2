#if !defined VETTORE_H_
#define VETTORE_H_

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

Vector* VectorRead(const char* filename);
Vector* VectorReadSorted(const char* filename);

#endif // !defined VETTORE_H_
