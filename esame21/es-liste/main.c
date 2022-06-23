#include <stdlib.h>

#include "list.h"

int main(void)
{
	Item* list = ListInsertHead(
		&(int) { 45 },
		ListInsertHead(
			&(int) { 8 },
			ListInsertHead(
				&(int) { 5 },
				ListInsertHead(
					&(int) { 2 },
					ListInsertHead(
						&(int) { 3 },
						ListInsertHead(
							&(int) { 45 },
							ListInsertHead(
								&(int) { 7 },
								ListInsertHead(
									&(int) { 5 },
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

	ListDelete(list);

	return 0;
}