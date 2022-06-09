#include "minheap.h"

#include <stdlib.h>
#include <string.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2)
{
	Heap* ret = HeapCreateEmpty();
	const Heap* concatena;

	if (h1->size > h2->size)
	{
		ret->size = h1->size;
		ret->data = memcpy(malloc(sizeof(ElemType) * ret->size), h1->data, sizeof(ElemType) * ret->size);
		concatena = h2;
	}
	else
	{
		ret->size = h2->size;
		ret->data = memcpy(malloc(sizeof(ElemType) * ret->size), h2->data, sizeof(ElemType) * ret->size);
		concatena = h1;
	}

	for (size_t i = 0; i < concatena->size; i++)
	{
		HeapMinInsertNode(ret, HeapGetNodeValue(concatena, i));
	}

	return ret;
}