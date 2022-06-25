#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <string.h>

const ElemType* Find(const Item* i, const char* name)
{
	const ElemType* ret = NULL;
	ElemType temp;
	
	strcpy(temp.name, name);
	
	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), &temp) == 0) {
			ret = ListGetHeadValue(i);
			break;
		}

		i = ListGetTail(i);
	}

	return ret;
}