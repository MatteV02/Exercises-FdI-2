#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

static void IsomorfiRec(const Node* t1, /*const Node* t2,*/ const Node* father2, bool* ret)
{
	if (*ret && !TreeIsEmpty(t1)) {
		if (father2->left && ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(father2->left)) == 0)
		{
			IsomorfiRec(TreeLeft(t1), /*TreeLeft(father2->left),*/ father2->left, ret);
			
			if (*ret == false) {
				*ret = true;
				IsomorfiRec(TreeLeft(t1), /*TreeRight(father2->left),*/ father2->left, ret);
				IsomorfiRec(TreeRight(t1), /*TreeLeft(father2->left),*/ father2->left, ret);
			}
			else {
				IsomorfiRec(TreeRight(t1), /*TreeRight(father2->left),*/ father2->left, ret);
			}
		}
		else if (father2->right && ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(father2->right)) == 0) 
		{
			IsomorfiRec(TreeLeft(t1), /*TreeLeft(father2->right),*/ father2->right, ret);

			if (*ret == false) {
				*ret = true;
				IsomorfiRec(TreeLeft(t1), /*TreeRight(father2->right),*/ father2->right, ret);
				IsomorfiRec(TreeRight(t1), /*TreeLeft(father2->right),*/ father2->right, ret);
			}
			else {
				IsomorfiRec(TreeRight(t1), /*TreeRight(father2->right),*/ father2->right, ret);
			}
		}
		else {
			*ret = false;
		}
		
	}
}

bool Isomorfi(const Node* t1, const Node* t2)
{
	bool ret = true;

	const Node fake_root2 = { .left = (Node*)t2, .right = NULL};

	IsomorfiRec(t1, /*t2,*/ &fake_root2, &ret);

	return ret;
}