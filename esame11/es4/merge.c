#include "minheap.h"

#include <stdlib.h>
#include <string.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2)
{
	Heap* ret = HeapCreateEmpty();

	ret->size = h1->size + h2->size;
	ret->data = memcpy(malloc(sizeof(ElemType) * (ret->size)), h1->data, sizeof(ElemType) * h1->size);

	for (size_t i = 0; i < h2->size; i++)
	{
		ret->data[h1->size + i] = h2->data[i];
		HeapMinMoveUp(ret, h1->size + i);
	}

	return ret;
}