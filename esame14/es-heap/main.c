#include <stdlib.h>
#include <string.h>

#include "minheap.h"

extern void HeapDeleteNode(Heap* h, int k);

int main(void)
{
	Heap* h = HeapCreateEmpty();

	h->size = 6;

	h->data = memcpy(
		malloc(sizeof(int) * h->size),
		(int[]) { 1, 3, 4, 6, 5, 23 },
		sizeof(int) * h->size
	);

	/*	HEAP
							 (    1)
				  +-------------+-------------+      
			   (    3)                     (    4)
		   +------+------+             +------+
		(    6)       (    5)       (   23)  
	*/

	HeapDeleteNode(h, 1);
	HeapDelete(h);

	return 0;
}