#include <stdlib.h>

#include "list.h"

#include "remove.h"

int main(void)
{
	Item* list = ListInsertHead(
		&(int) { 1 },
		ListInsertHead(
			&(int) { 2 },
			ListInsertHead(
				&(int) { 2 },
				ListInsertHead(
					&(int) { 2 },
					ListInsertHead(
						&(int) { 2 },
						ListInsertHead(
							&(int) { 2 },
							ListInsertHead(
								&(int) { 2 },
								ListInsertHead(
									&(int) { 2 },
									NULL
								)
							)
						)
					)
				)
			)
		)
	);

	/*  LISTA
		[45, 8, 5, 2, 3, 45, 7, 5]
	*/

	RemoveDuplicates(list);

	ListDelete(list);

	return 0;
}