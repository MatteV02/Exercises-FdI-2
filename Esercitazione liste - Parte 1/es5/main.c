#include <stdlib.h>

#include "list.h"

const ElemType* MaxElement(const Item* i);
Item* ListLoad(const char* filename);

int main(void)
{
	Item* list = ListLoad("data_00.txt");

	const ElemType* ret = MaxElement(list);

	ListDelete(list);

	return EXIT_SUCCESS;
}