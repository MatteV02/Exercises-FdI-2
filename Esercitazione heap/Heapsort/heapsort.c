#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "minheap.h"

static bool HeapMinPop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	--(h->size);
	//h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, 0);

	return true;

}

void HeapMinHeapsort(Heap* h)
{
	//ElemType* vec = malloc(h->size * sizeof(ElemType));
	size_t /*i_vec = h->size - 1,*/ size = h->size;
	ElemType temp;

	while (HeapMinPop(h, &temp)) /*{
		vec[i_vec--] = ElemCopy(&temp);
	}*/;

	//memcpy(h->data, vec, sizeof(ElemType) * size);
	h->size = size;

	//free(vec);
}