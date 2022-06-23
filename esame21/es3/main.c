#include <stdlib.h>

#include "list.h"

#include "differenza.h"

int main(void)
{
	Item* l1 = ListInsertHead(
		&(char) { '0' },
		ListInsertHead(
			&(char) { '0' },
			ListInsertHead(
				&(char) { '0' },
				ListInsertHead(
					&(char) { '1' },
					NULL
				)
			)
		)
	);

	Item* l2 = ListInsertHead(
		&(char) { '1' },
		NULL
	);

	Item* ret = Differenza(l1, l2);

	return 0;
}