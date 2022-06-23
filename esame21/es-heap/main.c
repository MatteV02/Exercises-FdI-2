#include <stdlib.h>
#include <string.h>

#include "minheap.h"

extern int KthLeast(const int* v, size_t n, int k);

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

	int v[] = { 9,8,7,6,5,4,3,2 };

	int ret = KthLeast(v, sizeof(v) / sizeof(*v), 2);

	HeapDelete(h);

	return 0;
}