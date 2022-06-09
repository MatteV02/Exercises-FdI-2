#include "list.h"

Item* ElementiPari(const Item* i)
{
	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}
	Item* ret = ListCreateEmpty();
	size_t j = 0;
	for (const Item* j_l = i; !ListIsEmpty(j_l); j_l = ListGetTail(j_l), ++j)
	{
		if (j % 2 == 0)
		{
			ret = ListInsertBack(ret, ListGetHeadValue(j_l));
		}
	}

	return ret;
}