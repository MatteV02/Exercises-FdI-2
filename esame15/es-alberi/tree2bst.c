#include "tree.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static void BstInsertRec(Node* ret, const ElemType* value, Node* father, bool right)
{
	if (TreeIsEmpty(ret))
	{
		if (right) {
			father->right = TreeCreateRoot(value, NULL, NULL);
		}
		else {
			father->left = TreeCreateRoot(value, NULL, NULL);
		}

		return;
	}

	if (ElemCompare(value, TreeGetRootValue(ret)) > 0) {
		BstInsertRec(TreeRight(ret), value, ret, true);
	}
	else
	{
		BstInsertRec(TreeLeft(ret), value, ret, false);
	}
}

static void Tree2BstRec(const Node* t, Node *ret)
{
	if (TreeIsEmpty(t)) {
		return;
	}

	Tree2BstRec(TreeLeft(t), ret);

	BstInsertRec(TreeLeft(ret), TreeGetRootValue(t), ret, false);

	Tree2BstRec(TreeRight(t), ret);

}

Node* Tree2Bst(const Node* t)
{
	Node* ret = TreeCreateRoot(&(ElemType) { INT32_MIN }, NULL, NULL), *temp;

	Tree2BstRec(t, ret);

	temp = ret;
	ret = TreeLeft(ret);
	free(temp);

	return ret;
}