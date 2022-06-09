#include "tree.h"

static bool Find(const Node* t, int key, const Node** father, int* h_key)
{
	if (TreeIsEmpty(t))
	{
		return false;
	}

	if (ElemCompare(TreeGetRootValue(t), &key) == 0)
	{
		return true;
	}

	bool ret;
	const Node* t_father = *father;
	*father = t;
	++(*h_key);

	ret = Find(TreeLeft(t), key, father, h_key);

	if (!ret) {
		ret = Find(TreeRight(t), key, father, h_key);
	}

	if (!ret) {
		// rollback
		--(*h_key);
		*father = t_father;
	}

	return ret;
}

bool Cugini(const Node* t, int a, int b)
{
	const Node* a_father, * b_father;
	int a_h = 0, b_h = 0;
	Find(t, a, &a_father, &a_h);
	Find(t, b, &b_father, &b_h);

	if (a_h != b_h || a_father == b_father)
	{
		return false;
	}

	return true;

}