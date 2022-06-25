#include <stdlib.h>
#include <stdbool.h>

#include "minheap.h"

extern bool IsHeap(const Heap* h);

int main(void)
{
	Heap h = { .data = (int[]){4, 6, 1, 3, 4}, .size = 5 };

	bool ret = IsHeap(&h);

	return 0;
}