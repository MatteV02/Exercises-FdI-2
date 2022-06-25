#include <stdlib.h>

#include "list.h"

extern Item* Diff(const Item* i1, const Item* i2);
extern Item* ListLoad(const char* filename);

int main(void)
{
	Item* i1 = ListLoad("data_00.txt");
	Item* i2 = ListLoad("data_01.txt");

	Item* ret = Diff(i1, i2);
	ListDelete(ret);

	ListDelete(i1);
	ListDelete(i2);

	return EXIT_SUCCESS;
}