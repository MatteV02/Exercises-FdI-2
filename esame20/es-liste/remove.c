#include "remove.h"

#include <stdlib.h>

Item* RemoveDuplicates(Item* i)
{
	if (i == NULL)
	{
		return NULL;
	}

	Item fake_head = { .value = i->value - 1, .next = i };
	Item* father = &fake_head;

	while (!ListIsEmpty(i))
	{
		if (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(father)) == 0) {
			father->next = ListGetTail(i);
			free(i);
			i = ListGetTail(father);
		}
		else {
			father = i;
			i = ListGetTail(i);
		}
	}

	return fake_head.next;
}