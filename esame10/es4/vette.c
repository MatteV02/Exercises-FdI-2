#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

int ContaVette(const Item* i)
{
	if (ListIsEmpty(i)) {
		return 0;
	}

	bool is_vetta = true;
	for (const Item* j = ListGetTail(i); !ListIsEmpty(j); j = ListGetTail(j)) {
		if (ElemCompare(ListGetHeadValue(j), ListGetHeadValue(i)) >= 0)
		{
			is_vetta = false;
			break;
		}
	}

	if (is_vetta) {
		return 1 + ContaVette(ListGetTail(i));
	}

	return ContaVette(ListGetTail(i));
}