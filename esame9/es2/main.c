#include <stdlib.h>

#include "colora.h"

int main(void)
{
	struct Matrix m = { 3, (bool[]) {
		true, true, true,
		true, true, false,
		true, false, true
	} };

	int ret = MappaColori(&m, (char[]) { 'r', 'v' }, 2);

	return EXIT_SUCCESS;
}