#include "list.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	ElemType* data;
	size_t capacity;
	size_t length;
} Vector;

static void VectorPushBack(Vector* v, const ElemType* el) 
{
	if (v->capacity == v->length) {
		if (v->capacity == 0) {
			v->capacity = 4;
		}

		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
	}

	v->data[v->length++] = *el;
}

static bool VectorSearch(const Vector* v, const ElemType* el)
{

	for (size_t i = 0; i < v->length; ++i) {
		if (ElemCompare(el, v->data + i) == 0) {
			return true;
		}
	}

	return false;
}

Item* Intersect(const Item* i1, const Item* i2)
{
	Vector i2_arr = {0};
	Item* ret = ListCreateEmpty();
	
	for (const Item* i = i2; !ListIsEmpty(i); i = ListGetTail(i)) {
		VectorPushBack(&i2_arr, ListGetHeadValue(i));
	}
	
	// Complessità = (O(i1_l*i2_l))
	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i)) {
		const ElemType* temp = ListGetHeadValue(i);
		if (VectorSearch(&i2_arr, temp)) {
			ret = ListInsertBack(ret, temp);
		}
	}

	free(i2_arr.data);
	return ret;
}