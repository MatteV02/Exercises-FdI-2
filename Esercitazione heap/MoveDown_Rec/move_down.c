#include <stdlib.h>

#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i)
{
	int min = i;

	if ((size_t)HeapLeft(i) < h->size && ElemCompare(HeapGetNodeValue(h, min), HeapGetNodeValue(h, HeapLeft(i))) > 0) {
		min = HeapLeft(i);
	}

	if ((size_t)HeapRight(i) < h->size && ElemCompare(HeapGetNodeValue(h, min), HeapGetNodeValue(h, HeapRight(i))) > 0) {
		min = HeapRight(i);
	}

	if (min != i) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, min));

		HeapMinMoveDownRec(h, min);
	}


}