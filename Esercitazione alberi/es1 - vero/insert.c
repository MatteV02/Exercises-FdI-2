#include "tree.h"

#include <stdint.h>

Node* BstInsert(const ElemType* e, Node* n)
{
	Node fake_root = { .left = n, .right = NULL };
	Node* father_left = &fake_root;
	Node* father_right = NULL;
	
	while (!TreeIsEmpty(n)) {
		if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
			father_left = n;
			father_right = NULL;
			n = TreeLeft(n);
		}
		else {
			father_left = NULL;
			father_right = n;
			n = TreeRight(n);
		}
	}

	if (father_left) {
		father_left->left = TreeCreateRoot(e, NULL, NULL);
	}
	else {
		father_right->right = TreeCreateRoot(e, NULL, NULL);
	}

	return fake_root.left;
}

Node* BstInsertRec(const ElemType* e, Node* n)
{
	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}

	if (ElemCompare(n, TreeGetRootValue(n)) <= 0)
	{
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else {
		n->right = BstInsertRec(e, TreeRight(n));
	}

	return n;
}