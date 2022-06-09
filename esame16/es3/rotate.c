#include <stdlib.h>

#include "list.h"

Item* Rotate(Item* i, int n)
{
	if (ListIsEmpty(i)) {
		return i;
	}

	Item fake_head = { .next = i };
	Item* ret = i;
	Item* father = &fake_head;

	while (n > 0) {
		father = ret;
		ret = ListGetTail(ret);
		--n;
	}

	father->next = NULL;

	i = ret;
	while (!ListIsEmpty(ListGetTail(i))) {
		i = ListGetTail(i);
	}

	i->next = fake_head.next;

	return ret;
}