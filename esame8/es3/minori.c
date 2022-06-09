#include "list.h"

Item* CreaDaMinori(const Item* i, int v)
{
	Item* ret = ListCreateEmpty();
	ElemType v_el = v;

	while (!ListIsEmpty(i)) {
		const ElemType *el = ListGetHeadValue(i);

		if (ElemCompare(el, &v_el) <= 0) {
			ret = ListInsertBack(ret, el);
		}

		i = ListGetTail(i);
	}

	return ret;
}