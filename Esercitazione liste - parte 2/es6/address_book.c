#include "list.h"

Item* Append(const Item* i1, const Item* i2)
{
	Item fake_head = { 0 };
	Item* last = &fake_head;

	while (!ListIsEmpty(i1))
	{
		last = ListInsertBack(last, ListGetHeadValue(i1));
		last = ListGetTail(last);

		i1 = ListGetTail(i1);
	}

	while (!ListIsEmpty(i2))
	{
		last = ListInsertBack(last, ListGetHeadValue(i2));
		last = ListGetTail(last);

		i2 = ListGetTail(i2);
	}

	return fake_head.next;
}