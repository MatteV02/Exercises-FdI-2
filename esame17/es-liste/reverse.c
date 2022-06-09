#include "list.h"

Item* Reverse(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}

	Item fake_head = { .next = i };
	Item* prev = &fake_head;
	Item* last;
	for (last = i; !ListIsEmpty(ListGetTail(last)); last = ListGetTail(last))
	{
		prev = last;
	}

	prev->next = NULL;
	last->next = Reverse(fake_head.next);
	
	return last;
}