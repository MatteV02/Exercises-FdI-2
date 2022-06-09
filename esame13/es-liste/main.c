#include <stdlib.h>

#include "list.h"

extern const Item* CommonTail(const Item* i1, const Item* i2);

int main(void)
{
	Item* list = ListInsertHead(
		&(int) { 8 },
		ListInsertHead(
			&(int) { 3 },
			ListInsertHead(
				&(int) { 6 },
				ListInsertHead(
					&(int) { 5 },
					ListInsertHead(
						&(int) { 4 },
						NULL
					)
				)
			)
		)
	);

	Item* list2 = ListInsertHead(
		&(int) { 7 },
		ListInsertHead(
			&(int) { 2 },
			list->next->next->next
		)
	);

	/*  LISTA
		[45, 8, 5, 2, 3, 45, 7, 5]
	*/

	Item* ret = CommonTail(list, list2);

	return 0;
}