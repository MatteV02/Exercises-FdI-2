#include "list.h"

#include <stdbool.h>

Item* PariDispari(Item* i)
{
	bool primo = true;
	Item* pari = NULL, * dispari = NULL, *ultimo_pari = NULL;

	while (!ListIsEmpty(i))
	{
		Item* next = ListGetTail(i);
		if (ElemCopy(ListGetHeadValue(i)) % 2 == 0) {
			if (primo)
			{
				primo = false;
				ultimo_pari = i;
			}
			i->next = pari;
			pari = i;
		}
		else {
			i->next = dispari;
			dispari = i;
		}

		i = next;
	}

	if (primo == false)
	{
		ultimo_pari->next = dispari;
		return pari;
	}
	else {
		return dispari;
	}
}