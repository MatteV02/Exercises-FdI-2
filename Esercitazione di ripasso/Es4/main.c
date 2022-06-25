#include "vettore.h"

int main(void)
{
	struct vettore v = {0};

	for (int i = 0; i < 10; i++) {
		Push(&v, i + 1);
	}

	for (int i = 0; i < 10; i++) {
		int c = Pop(&v);
		c++;
	}

	return 0;
}