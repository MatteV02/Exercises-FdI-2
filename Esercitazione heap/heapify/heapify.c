#include <stdlib.h>

#include "minheap.h"

Heap* HeapMinHeapify(const ElemType* v, size_t v_size)
{
	Heap* ret = HeapCreateEmpty();

	if (v != NULL) {
		for (size_t i = 0; i < v_size; ++i) {
			HeapMinInsertNode(ret, v + i);
		}
	}

	return ret;
}