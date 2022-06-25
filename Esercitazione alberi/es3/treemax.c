#include "tree.h"

#include <stdint.h>

const ElemType* BstTreeMax(const Node* n)
{
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	if (TreeRight(n) == NULL) {
		return TreeGetRootValue(n);
	}
	return BstTreeMax(TreeRight(n));
}



void TreeMaxRec(const Node* n, size_t i, const ElemType** max, size_t *i_max)
{
	if (!TreeIsEmpty(n))
	{
		/*if (ElemCompare(TreeGetRootValue(n), *max) > 0) {
			*max = TreeGetRootValue(n);
			*i_max = i;
		}
		else if (i < *i_max && ElemCompare(TreeGetRootValue(n), *max) == 0) {
			*max = TreeGetRootValue(n);
			*i_max = i;
		}*/

		if (ElemCompare(TreeGetRootValue(n), *max) > 0 || 
			(i < *i_max && ElemCompare(TreeGetRootValue(n), *max) == 0)) 
		{
			*max = TreeGetRootValue(n);
			*i_max = i;
		}

		TreeMaxRec(TreeLeft(n), i + 1, max, i_max);
		TreeMaxRec(TreeRight(n), i + 1, max, i_max);
	}
}

const ElemType* TreeMax(const Node* n)
{
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* max = TreeGetRootValue(n);
	size_t i_max = 0;

	TreeMaxRec(TreeLeft(n), 1, &max, &i_max);
	TreeMaxRec(TreeRight(n), 1, &max, &i_max);

	return max;
}