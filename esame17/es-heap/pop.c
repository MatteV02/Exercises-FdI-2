#include "minheap.h"

#include <stdlib.h>
#include <stdbool.h>

static void MyElemSwap(ElemType* a, ElemType* b)
{
	ElemType tmp = ElemCopy(a);
	*a = ElemCopy(b);
	*b = tmp;
}

bool Pop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h))
	{
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));
	MyElemSwap(h->data, h->data + h->size - 1);
	--(h->size);
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	HeapMinMoveDown(h, 0);

	return true;
}