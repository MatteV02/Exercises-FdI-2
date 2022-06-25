#include <stdlib.h>

#include "maxheap.h"

Heap* Heapify(const ElemType* v, size_t v_size)
{
	Heap* ret = HeapCreateEmpty();

	if (v != NULL) {
		for (size_t i = 0; i < v_size; ++i) {
			HeapMaxInsertNode(ret, v + i);
		}
	}

	return ret;
}

bool Pop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	--(h->size);
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMaxMoveDown(h, 0);

	return true;

}

static bool Pop_forHeapsort(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	--(h->size);
	//h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMaxMoveDown(h, 0);

	return true;

}

extern void Heapsort(Heap* h)
{
	//ElemType* vec = malloc(h->size * sizeof(ElemType));
	size_t /*i_vec = h->size - 1,*/ size = h->size;
	ElemType temp;

	while (Pop_forHeapsort(h, &temp)) /*{
		vec[i_vec--] = ElemCopy(&temp);
	}*/;

	//memcpy(h->data, vec, sizeof(ElemType) * size);

	h->size = size;

}