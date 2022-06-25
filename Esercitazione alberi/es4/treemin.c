#include <stdlib.h>

#include "tree.h"

const ElemType* BstTreeMin(const Node* n)
{
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	while (TreeIsEmpty(TreeLeft(n)))
	{
		n = TreeLeft(n);
	}

	return TreeGetRootValue(n);
}

static void TreeMinRec(const Node* n, size_t i, const ElemType** min, size_t* i_min)
{
	if (TreeIsEmpty(n))
	{
		return;
	}
	 
	if (ElemCompare(TreeGetRootValue(n), *min) < 0 || 
		(i > *i_min && ElemCompare(TreeGetRootValue(n), *min) == 0))
	{
		*min = TreeGetRootValue(n);
		*i_min = i;
	}

	TreeMinRec(TreeLeft(n), i + 1, min, i_min);
	TreeMinRec(TreeRight(n), i + 1, min, i_min);
}

const ElemType* TreeMin(const Node* n)
{
	const ElemType* min = NULL;
	
	if (!TreeIsEmpty(n))
	{
		min = TreeGetRootValue(n);
		size_t i_min = 0;

		TreeMinRec(TreeLeft(n), 1, &min, &i_min);
		TreeMinRec(TreeRight(n), 1, &min, &i_min);
	}

	return min;
}