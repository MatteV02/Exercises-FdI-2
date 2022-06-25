#include <stdlib.h>
#include "sciatori.h"

int main(void)
{
	double altezze[] = { 81.5,34.2,100,96.8 };
	double lunghezze[] = { 100.2,30.1,150.12,200.1 };

	Sciatore* ret = Accoppia(altezze, lunghezze, sizeof(altezze) / sizeof(*altezze));

	free(ret);

	return EXIT_SUCCESS;
}