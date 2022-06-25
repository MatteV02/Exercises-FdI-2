#include "list.h"

Item* Sort(Item* i)
{
	if (!ListIsEmpty(i)) {
		Item* da_ordinare = ListGetTail(i);
		Item* ordinati = i;
		ordinati->next = NULL;

		while (!ListIsEmpty(da_ordinare))
		{
			Item* prev_ordinati = NULL;
			Item* i_ordinati;
			for (i_ordinati = ordinati; !ListIsEmpty(i_ordinati) && ElemCompare(ListGetHeadValue(i_ordinati), ListGetHeadValue(da_ordinare)) < 0; i_ordinati = ListGetTail(i_ordinati))
			{
				prev_ordinati = i_ordinati;
			}

			if (prev_ordinati == NULL) {
				ordinati = da_ordinare;
			}
			else {
				prev_ordinati->next = da_ordinare;
			}
			
			Item* temp = da_ordinare->next;
			da_ordinare->next = i_ordinati;

			da_ordinare = temp;
		}

		i = ordinati;
	}

	return i;
}