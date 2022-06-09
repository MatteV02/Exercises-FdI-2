#include "list.h"

#include <stdlib.h>
#include <math.h>

Item* CreaDaInterni(const Item* i, double r)
{
	Item* ret = ListCreateEmpty();

	while (!ListIsEmpty(i))
	{
		if (sqrt(pow(i->value.x, 2) + pow(i->value.y, 2)) < r) {
			ret = ListInsertBack(ret, &i->value);
		}

		i = ListGetTail(i);
	}

	return ret;
}