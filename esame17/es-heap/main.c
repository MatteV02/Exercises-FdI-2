#include <stdlib.h>
#include <string.h>

#include "minheap.h"

extern bool Pop(Heap* h, ElemType* e);

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

	ElemType e;
	bool ret = Pop(h, &e);

	HeapDelete(h);

	return 0;
}