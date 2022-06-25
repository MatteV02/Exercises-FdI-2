#include <stdlib.h>

#include "tree.h"

extern const ElemType* BstTreeMax(const Node* n);
extern const ElemType* TreeMax(const Node* n);

int main(void)
{
	const ElemType* ret = TreeMax(NULL);

	return 0;
}