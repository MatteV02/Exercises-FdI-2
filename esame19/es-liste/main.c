#include <stdlib.h>

#include "list.h"

extern Item* PariDispari(Item* i);

int main(void)
{
	Item* list = ListInsertHead(
		&(int) { 1 },
		ListInsertHead(
			&(int) { 3 },
			ListInsertHead(
				&(int) { 4 },
				ListInsertHead(
					&(int) { 7 },
					ListInsertHead(
						&(int) { 8 },
						ListInsertHead(
							&(int) { -2 },
							NULL
						)
					)
				)
			)
		)
	);

	/*  LISTA
		[45, 8, 5, 2, 3, 45, 7, 5]
	*/

	list = PariDispari(list);

	ListDelete(list);

	return 0;
}