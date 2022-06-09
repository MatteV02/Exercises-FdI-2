#include "minheap.h"

#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k)
{
	if (k < 0 || (size_t)k >= h->size)
	{
		return;
	}

	ElemSwap(h->data + k, h->data + h->size - 1);

	--(h->size);
	h->data = realloc(h->data, sizeof(int) * h->size);

	HeapMinMoveDown(h, k);

}