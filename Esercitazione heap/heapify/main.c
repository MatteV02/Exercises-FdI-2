#include <stdlib.h>

#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void)
{
	int v[] = { 9,8,7,6,5,4,3,2,1 };
	Heap* ret = HeapMinHeapify(v, sizeof(v) / sizeof(*v));

	HeapDelete(ret);

	return 0;
}