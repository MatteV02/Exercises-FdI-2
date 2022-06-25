#include "tree.h"

static void TreeIsMirrorRec(const Node* t_left, const Node* t_right, bool* ret)
{
	if (*ret) {
		if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right)) {
			return;
		}
		
		if ((TreeIsEmpty(t_left) && !TreeIsEmpty(t_right)) || (!TreeIsEmpty(t_left) && TreeIsEmpty(t_right))) {
			*ret = false;
			return;
		}

		TreeIsMirrorRec(TreeLeft(t_left), TreeRight(t_right), ret);
		TreeIsMirrorRec(TreeRight(t_left), TreeLeft(t_right), ret);

		if (ElemCompare(TreeGetRootValue(t_left), TreeGetRootValue(t_right)) != 0) {
			*ret = false;
			return;
		}
	}
}

bool TreeIsMirror(const Node* t)
{
	bool ret = true;
	
	TreeIsMirrorRec(TreeLeft(t), TreeRight(t), &ret);
	
	return ret;
}