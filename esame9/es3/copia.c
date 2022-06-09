#include "list.h"

Item* CopiaDaN(const Item* i, int n)
{
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	Item* prev = CopiaDaN(ListGetTail(i), --n);
	

	if (n > 0) {
		return prev;
	}
	else {
		return ListInsertHead(ListGetHeadValue(i), prev);
	}

}