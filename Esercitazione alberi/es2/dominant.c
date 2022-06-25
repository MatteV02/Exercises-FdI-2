#include "tree.h"

void CountDominantRec(const Node* t, int* sum)
{
	if (!TreeIsLeaf(t)) {
		ElemType left;
		if (TreeLeft(t)) {
			left = ElemCopy(TreeGetRootValue(TreeLeft(t)));
		}
		else {
			left = 0;
		}

		ElemType right;
		if (TreeRight(t)) {
			right = ElemCopy(TreeGetRootValue(TreeRight(t)));
		}
		else {
			right = 0;
		}

		if (ElemCopy(TreeGetRootValue(t)) > left + right)
		{
			++(*sum);
		}

		CountDominantRec(TreeLeft(t), sum);
		CountDominantRec(TreeRight(t), sum);
	}
}

int CountDominant(const Node* t)
{
	int sum = 0;

	CountDominantRec(t, &sum);

	return sum;
}