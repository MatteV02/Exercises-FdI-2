#include "list.h"

Item* Reverse(const Item* i)
{
	Item* ret = ListCreateEmpty();

	while (!ListIsEmpty(i))
	{
		ret = ListInsertHead(ListGetHeadValue(i), ret);

		i = ListGetTail(i);
	}

	return ret;
}