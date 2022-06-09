#include "list.h"

#include <stdbool.h>

static Item* SumRec(const Item* i1, const Item* i2, bool riporto)
{
	ElemType sum = riporto ? 1 : 0;
	riporto = false;

	if (ListIsEmpty(i1) && ListIsEmpty(i2))
	{
		if (sum)
		{
			return ListInsertHead(&sum, NULL);
		}
		else {
			return ListCreateEmpty();
		}
	}

	Item* next1, * next2;
	ElemType head_1, head_2;

	if (ListIsEmpty(i1))
	{
		head_1 = 0;
		next1 = NULL;
	}
	else {
		head_1 = ElemCopy(ListGetHeadValue(i1));
		next1 = ListGetTail(i1);
	}

	if (ListIsEmpty(i2))
	{
		head_2 = 0;
		next2 = NULL;
	}
	else {
		head_2 = ElemCopy(ListGetHeadValue(i2));
		next2 = ListGetTail(i2);
	}

	sum += head_1 + head_2;

	if (sum >= 10) {
		riporto = true;
		sum %= 10;
	}

	return ListInsertHead(&sum, SumRec(next1, next2, riporto));

}

Item* Sum(const Item* i1, const Item* i2)
{
	return SumRec(i1, i2, false);
}