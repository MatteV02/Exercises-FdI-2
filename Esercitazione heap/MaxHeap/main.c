#include <stdlib.h>
#include <string.h>

#include "maxheap.h"

extern Heap* Heapify(const ElemType* v, size_t v_size);
extern bool Pop(Heap* h, ElemType* e);
extern void Heapsort(Heap* h);

int main(void)
{
	ElemType v[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };

	Heap* h = Heapify(v, sizeof(v) / sizeof(*v));

	ElemType el;

	bool ret = Pop(h, &el);

	Heapsort(h);

	HeapDelete(h);

	return 0;
}