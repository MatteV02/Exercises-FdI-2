#include "minheap.h"

void IsHeapRec(const Heap* h, size_t pos, bool* ret)
{
	if (*ret == false)
	{
		return;
	}

	if (HeapLeft(pos) < (int)h->size)
	{
		if (ElemCompare(HeapGetNodeValue(h, HeapLeft(pos)), HeapGetNodeValue(h, pos)) < 0)
		{
			*ret = false;
		}
	}

	if (HeapRight(pos) < (int)h->size)
	{
		if (ElemCompare(HeapGetNodeValue(h, HeapRight(pos)), HeapGetNodeValue(h, pos)) < 0)
		{
			*ret = false;
		}
	}
}

bool IsHeap(const Heap* h)
{
	bool ret = true;

	IsHeapRec(h, 0, &ret);

	return ret;
}