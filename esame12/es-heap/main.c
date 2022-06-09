#include <stdlib.h>
#include <string.h>

#include "minheap.h"

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

int main(void)
{
	Heap* h = HeapCreateEmpty();

	h->size = 6;

	h->data = memcpy(
		malloc(sizeof(int) * h->size),
		(int[]) { 1, 3, 4, 6, 5, 23 },
		sizeof(int) * h->size
	);

	Heap* h1 = HeapCreateEmpty();

	h1->size = 1;

	h1->data = memcpy(
		malloc(sizeof(int) * h->size),
		(int[]) {0},
		sizeof(int)* h1->size
	);

	/*	HEAP
							 (    1)
				  +-------------+-------------+      
			   (    3)                     (    4)
		   +------+------+             +------+
		(    6)       (    5)       (   23)  
	*/

	Heap* ret = MergeHeap(h, h1);

	HeapDelete(h);
	HeapDelete(h1);
	HeapDelete(ret);

	return 0;
}