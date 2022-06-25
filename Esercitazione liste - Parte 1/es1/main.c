#include <stdlib.h>

#include "list.h"

extern Item* ListLoad(const char* filename);

int main(void)
{
	Item* ret = ListLoad("data_00.txt");

	ListDelete(ret);

	return 0;
}