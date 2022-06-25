#include <stdlib.h>

#include "list.h"

extern Item* Intersect(const Item* i1, const Item* i2);
extern Item* ListLoad(const char* filename);

int main(void)
{
	Item* i1 = ListLoad("data_00.txt");
	Item* i2 = ListLoad("data_01.txt");

	Item* ret = Intersect(i1, i2);

	ListDelete(ret);

	return EXIT_SUCCESS;
}