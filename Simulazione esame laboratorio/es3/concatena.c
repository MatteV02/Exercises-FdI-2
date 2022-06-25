#include "list.h"

#include <stdlib.h>

Item* ConcatenaN(Item** v, size_t v_size)
{
	Item fake_head = { .next = ListCreateEmpty() };

	Item* padre_coda_attuale = &fake_head;

	for (size_t i = 0; i < v_size; i++)
	{
		padre_coda_attuale->next = v[i];

		while (!ListIsEmpty(ListGetTail(padre_coda_attuale)))
		{
			padre_coda_attuale = ListGetTail(padre_coda_attuale);
		}
	}

	return fake_head.next;
}