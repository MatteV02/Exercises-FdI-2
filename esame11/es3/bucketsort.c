#include "list.h"

#include <stdlib.h>

Item* ListInsertBack_noAlloc(Item* l, Item* el)
{
	el->next = NULL;
	if (l == NULL)
	{
		return el;
	}

	Item* i;
	for (i = l; !ListIsEmpty(ListGetTail(i)); i = ListGetTail(i));

	i->next = el;

	return l;
}

Item* BucketSort(Item* l)
{
	int min, max, length;
	GetMinMaxSize(l, &min, &max, &length);

	if (length < 1)
		return ListCreateEmpty();
	else if (length == 1) {
		return l;
	}

	Item** v = calloc(length, sizeof(Item*));

	for (Item* i = l; !ListIsEmpty(i); )
	{
		int bucket_pos = (length - 1) * (*ListGetHeadValue(i) - min) / (max - min);
		
		Item* temp = ListGetTail(i);
		v[bucket_pos] = ListInsertBack_noAlloc(v[bucket_pos], i);
		i = temp;
	}

	Item* ret = ListCreateEmpty();
	for (int i = 0; i < length; ++i)
	{
		ret = ConcatList(ret, BucketSort(v[i]));
	}

	free(v);

	return ret;
}