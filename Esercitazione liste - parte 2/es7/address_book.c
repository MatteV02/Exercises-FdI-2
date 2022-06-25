#include "list.h"

Item* AppendMod(Item* i1, Item* i2)
{
	Item fake_head = { .next = i1 };
	Item* last1 = &fake_head;

	while (!ListIsEmpty(i1))
	{
		last1 = i1;

		i1 = ListGetTail(i1);
	}

	last1->next = i2;

	return fake_head.next;
}