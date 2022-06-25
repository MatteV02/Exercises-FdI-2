#include <stdlib.h>

#include "list.h"

extern Item* IntersectNoRep(const Item* i1, const Item* i2);
extern Item* DiffNoRep(const Item* i1, const Item* i2);
extern Item* ListLoad(const char* filename);

int main(void)
{
	Item* i1 = ListLoad("data_00.txt");
	Item* i2 = ListLoad("data_01.txt");

	Item* ret = DiffNoRep(i1, i2);
	ListDelete(ret);

	ret = IntersectNoRep(i1, i2);
	ListDelete(ret);

	ListDelete(i1);
	ListDelete(i2);

	return EXIT_SUCCESS;

	return EXIT_SUCCESS;
}