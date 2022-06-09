#include "minheap.h"

#include <stdlib.h>
#include <string.h>

ElemType KthLeast(const Heap* h, int k)
{
	Heap* h_copy = HeapCreateEmpty();
	h_copy->size = h->size;
	h_copy->data = memcpy(malloc(sizeof(ElemType) * h_copy->size), h->data, sizeof(ElemType) * h_copy->size);

	ElemType ret;

	for (int i = 1; i < k; ++i)
	{
		--(h_copy->size);
		ElemSwap(h_copy->data, h_copy->data + h_copy->size);
		h_copy->data = realloc(h_copy->data, h_copy->size * sizeof(ElemType));
		HeapMinMoveDown(h_copy, 0);
	}

	ret = ElemCopy(HeapGetNodeValue(h_copy, 0));

	HeapDelete(h_copy);

	return ret;
}