#include "list.h"

#include <stdint.h>

const ElemType* MaxElement(const Item* i)
{
	const ElemType* ret = NULL;
	ElemType ret_value = INT32_MIN;
	
	while (!ListIsEmpty(i)) {
		const ElemType* temp = ListGetHeadValue(i);
		
		if (ElemCompare(temp, &ret_value) > 0) {
			ret_value = *temp;
			ret = temp;
		}

		i = ListGetTail(i);
	}

	return ret;
}