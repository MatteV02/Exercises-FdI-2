#include <stdlib.h>

#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void)
{
	Node* ret = TreeRead("albero1.txt");

	TreeDelete(ret);

	return 0;
}