#include <stdlib.h>

#include "minheap.h"

bool HeapMinPop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	--(h->size);
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, 0);

	return true;

}