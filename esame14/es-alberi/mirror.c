#include "tree.h"

#include <stdbool.h>

void TreeIsMirrorRec(Node* t_left, Node* t_right, bool* ret)
{
	if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right))
	{
		return;
	}

	if ((TreeIsEmpty(t_left) && !TreeIsEmpty(t_right)) || (!TreeIsEmpty(t_left) && TreeIsEmpty(t_right)))
	{
		*ret = false;
		return;
	}

	TreeIsMirrorRec(TreeLeft(t_left), TreeRight(t_right), ret);

	if (!*ret) {
		return;
	}

	TreeIsMirrorRec(TreeRight(t_left), TreeLeft(t_right), ret);

	if (!*ret)
	{
		return;
	}

	if (ElemCompare(TreeGetRootValue(t_left), TreeGetRootValue(t_right)) != 0)
	{
		*ret = false;
		return;
	}
}

bool TreeIsMirror(Node* t)
{
	bool ret = true;

	if (!TreeIsEmpty(t))
	{
		TreeIsMirrorRec(TreeLeft(t), TreeRight(t), &ret);
	}

	return ret;
}