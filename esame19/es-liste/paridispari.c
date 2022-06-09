#include <stdlib.h>

#include "list.h"

Item* PariDispari(Item* i)
{
	Item coda_pari = { 0 },
		coda_dispari = { 0 };
	Item* last_pari = &coda_pari,
		* last_dispari = &coda_dispari;

	for (Item* j = i; !ListIsEmpty(j); j = ListGetTail(j))
	{
		if (j->value % 2 == 0)
		{
			last_pari->next = j;
			last_pari = j;
		}
		else {
			last_dispari->next = j;
			last_dispari = j;
		}
	}

	last_pari->next = coda_dispari.next;
	last_dispari->next = NULL;

	return coda_pari.next;
}