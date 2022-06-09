#include <stdlib.h>

#include "list.h"

Item* ListCreateFromVector(int* v, size_t v_len)
{
	if (v_len > 0)
	{
		return ListInsertHead(v, ListCreateFromVector(v + 1, v_len - 1));
	}
	else {
		return ListCreateEmpty();
	}
}

extern Item* Sum(const Item* i1, const Item* i2);

int main(void)
{
	int v1[] = {8, 1, 5, 6, 1, 5, 6, 8, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9};
	int v2[] = { 3, 2, 2, 4, 6, 1, 1, 6, 8, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 };

	Item* list1 = //ListCreateFromVector(v1, sizeof(v1) / sizeof(*v1));
	ListInsertHead(
		&(int) { /*4*/ 7 },
		/*ListInsertHead(
			&(int) { 8 },
			ListInsertHead(
				&(int) { 5 },
				ListInsertHead(
					&(int) { 2 },
					NULL
				)
			)
		)*/ NULL
	);

	Item* list2 = //ListCreateFromVector(v2, sizeof(v2) / sizeof(*v2));
		ListInsertHead(
		&(int) { 3 },
		/*ListInsertHead(
			&(int) { 5 },
			ListInsertHead(
				&(int) { 7 },
				ListInsertHead(
					&(int) { 5 },
					NULL
				)
			)
		)*/ NULL
	);

	/*  LISTA
		[4, 8, 5, 2]
		[3, 5, 7, 5]
	*/

	Item* ret = Sum(list1, list2);

	ListDelete(list1);
	ListDelete(list2);
	ListDelete(ret);

	return 0;
}