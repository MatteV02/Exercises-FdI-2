#include <stdlib.h>

#include "list.h"

extern Item* ElementiPari(const Item* i);

int main(void)
{
	Item* list = ListInsertHead(
		&(int) { 1 },
		ListInsertHead(
			&(int) { 0 },
			ListInsertHead(
				&(int) { 3 },
				ListInsertHead(
					&(int) { 2 },
					ListInsertHead(
						&(int) { 5 },
						/*ListInsertHead(
							&(int) { 45 },
							ListInsertHead(
								&(int) { 7 },
								ListInsertHead(
									&(int) { 5 },
									NULL
								)
							)
						)*/	NULL
					)
				)
			)
		)
	);

	/*  LISTA
		[45, 8, 5, 2, 3, 45, 7, 5]
	*/

	Item* ret = ElementiPari(NULL);

	ListDelete(list);

	return 0;
}