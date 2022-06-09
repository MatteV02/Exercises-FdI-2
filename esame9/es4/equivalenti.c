#include "tree.h"

static void EquivalentiRec(const Node* t1, const Node* t2, bool* ret)
{
	if (*ret) {

		if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
			return;
		}

		if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
			*ret = false;
			return;
		}

		EquivalentiRec(TreeLeft(t1), TreeLeft(t2), ret);
		EquivalentiRec(TreeRight(t1), TreeRight(t2), ret);

		if (TreeIsLeaf(t1)) {
			if (*TreeGetRootValue(t1) % *TreeGetRootValue(t2) != 0 && *TreeGetRootValue(t2) % *TreeGetRootValue(t1) != 0) {
				*ret = false;
				return;
			}
		}
		else {
			if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
				*ret = false;
				return;
			}
		}
	}
}

bool Equivalenti(const Node* t1, const Node* t2)
{
	bool ret = true;

	EquivalentiRec(t1, t2, &ret);

	return ret;
}