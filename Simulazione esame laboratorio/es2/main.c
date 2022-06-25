#include <stdlib.h>

#include "prezzo.h"

int main(void)
{
	struct Articolo a[] = { {"Monopoli", 20}, {"Carcassone", 30}, {"Perudo", 20} };

	TrovaArticoli(a, sizeof(a) / sizeof(*a), 50);

	return 0;
}