#include "list.h"

static bool ListSearchFinoA(const Item* list, const ElemType* el, const Item* fino_a)
{
	while (list != fino_a) {
		if (ElemCompare(&list->value, el) == 0) {
			return true;
		}

		list = ListGetTail(list);
	}

	return false;
}

static Item* ListInsertBack_custom(Item** list_last, const ElemType* el)
{
	Item* temp = ListInsertBack(*list_last, el);

	if (*list_last == NULL) {
		*list_last = temp;
		return temp;
	}
	else {
		*list_last = ListGetTail(temp);
		return NULL;
	}

}

Item* IntersectNoRep(const Item* i1, const Item* i2)
{
	Item* ret = ListCreateEmpty();
	Item* ret_last = ret;

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i))
	{
		const ElemType* temp = &i->value;

		if (ListSearchFinoA(i1, temp, i) == false) {
			if (ListSearchFinoA(i2, temp, ListCreateEmpty()) == true) {

				Item* ret_temp = ListInsertBack_custom(&ret_last, temp);
				if (ret_temp) {
					ret = ret_temp;
				}
			}
		}
	}

	return ret;

}

Item* DiffNoRep(const Item* i1, const Item* i2)
{
	Item* ret = ListCreateEmpty();
	Item* ret_last = ret;

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i))
	{
		const ElemType* temp = &i->value;
		
		if (ListSearchFinoA(i1, temp, i) == false) {
			if (ListSearchFinoA(i2, temp, NULL) == false) {

				Item* ret_temp = ListInsertBack_custom(&ret_last, temp);
				if (ret_temp) {
					ret = ret_temp;
				}
			}
		}
	}

	return ret;
}