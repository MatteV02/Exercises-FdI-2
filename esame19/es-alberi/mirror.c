#include "tree.h"

#include <stdbool.h>

static bool TreeisMirrorRec(Node* t_left, Node* t_right)
{
	if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right))
	{
		return true;
	}

	if ((TreeIsEmpty(t_left) && !TreeIsEmpty(t_right)) || (!TreeIsEmpty(t_left) && TreeIsEmpty(t_right)))
	{
		return false;
	}

	bool ret;
	ret = TreeisMirrorRec(TreeLeft(t_left), TreeRight(t_right));

	if (ret)
	{
		ret = TreeisMirrorRec(TreeRight(t_left), TreeLeft(t_right));

		if (ret)
		{
			if (ElemCompare(TreeGetRootValue(t_left), TreeGetRootValue(t_right)) != 0)
			{
				ret = false;
			}
		}
	}
	
	return ret;
}

bool TreeIsMirror(Node* t)
{
	if (TreeIsLeaf(t))
	{
		return true;
	}

	return TreeisMirrorRec(TreeLeft(t), TreeRight(t));

}