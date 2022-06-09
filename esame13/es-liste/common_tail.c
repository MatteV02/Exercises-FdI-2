#include "list.h"

#include <stdlib.h>

static const Item* CommonTailRec(const Item* i1, const Item* i2)
{
	const Item* i1_next = ListGetTail(i1);
	const Item* i2_next = ListGetTail(i2);
	if (ListIsEmpty(i1_next) && ListIsEmpty(i2_next))
	{
		if (i1 == i2) {
			return i1;
		}
		else {
			return NULL;
		}
	}

	if (ListIsEmpty(i1_next))
	{
		i1_next = i1;
	}

	if (ListIsEmpty(i2_next))
	{
		i2_next = i2;
	}

	const Item* ret = CommonTailRec(i1_next, i2_next);

	if (ret)
	{
		if (i1 == i2) {
			return i1;
		}
		else {
			return ret;
		}
	}
	else {
		return NULL;
	}
}

const Item* CommonTail(const Item* i1, const Item* i2)
{
	if (ListIsEmpty(i1) || ListIsEmpty(i2))
	{
		return NULL;
	}

	size_t i1_length = 0, i2_length = 0;

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i))
		i1_length++;

	for (const Item* i = i2; !ListIsEmpty(i); i = ListGetTail(i))
		i2_length++;

	if (i1_length >= i2_length)
	{
		while (i1_length > i2_length) {
			i1 = ListGetTail(i1);
			i1_length--;
		}
	}
	else {
		while (i2_length > i1_length) {
			i2 = ListGetTail(i2);
			i2_length--;
		}
	}

	return CommonTailRec(i1, i2);
}