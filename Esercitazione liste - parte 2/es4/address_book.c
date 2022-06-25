#include "list.h"

#include <string.h>

Item* Filtra(const Item* i, const char* city)
{
	Item fake_head = { 0 };
	Item* last = &fake_head;
	ElemType temp;

	strcpy(temp.city, city);

	while (!ListIsEmpty(i))
	{
		if (ElemCompare(ListGetHeadValue(i), &temp) == 0) {
			ListInsertBack(last, ListGetHeadValue(i));
			last = ListGetTail(last);
		}

		i = ListGetTail(i);
	}

	return fake_head.next;
}