#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <stdio.h>

Item* ListLoad(const char* filename)
{
	Item* ret = ListCreateEmpty();

	FILE* f = fopen(filename, "rt");

	if (f != NULL) {

		while (1) {
			ElemType temp;

			int ret_ElemRead = ElemRead(f, &temp);

			if (ret_ElemRead != 1) {
				break;
			}

			ret = ListInsertHead(&temp, ret);

		}

		fclose(f);
	}

	return ret;
}