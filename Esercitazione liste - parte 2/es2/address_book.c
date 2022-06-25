#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <string.h>

static Item* Find(Item* i, const char* name, Item** prev)
{
	Item* ret = NULL;

	ElemType temp;

	strcpy(temp.name, name);

	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), &temp) == 0) {
			ret = i;
			break;
		}

		*prev = i;
		i = ListGetTail(i);
	}

	return ret;
}

Item* Delete(Item* i, const char* name)
{
	Item* el;
	Item* prev = NULL;

	el = Find(i, name, &prev);

	if (el != NULL) {
		if (prev != NULL) {
			prev->next = el->next;
		}
		else {
			i = ListGetTail(i);
		}

		el->next = NULL;

		ListDelete(el);
	}

	return i;
}