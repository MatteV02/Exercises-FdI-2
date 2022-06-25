#include <stdlib.h>
#include "gioielli.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main(void)
{
	size_t ret_size;
	Gioiello* ret = CompraGioielli("gioielli_1.txt", 121, &ret_size);

	free(ret);

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}