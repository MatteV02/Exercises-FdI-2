#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

static void ProvaSomme(const Node* t, const Node* a, int n, bool* ret)
{
	if (t != a && t->value + a->value == n)
	{
		*ret = true;
	}

	if (*ret)
	{
		return;
	}

	if (!TreeIsEmpty(TreeLeft(t)))
	{
		ProvaSomme(TreeLeft(t), a, n, ret);
	}

	if (!TreeIsEmpty(TreeRight(t)))
	{
		ProvaSomme(TreeRight(t), a, n, ret);
	}
}

static void FissaPrimoAddendo(const Node* t, const Node* a, int n, bool* ret)
{
	ProvaSomme(t, a, n, ret);

	if (*ret)
	{
		return;
	}

	if (!TreeIsEmpty(TreeLeft(a)))
	{
		FissaPrimoAddendo(t, TreeLeft(a), n, ret);
	}

	if (!TreeIsEmpty(TreeRight(a)))
	{
		FissaPrimoAddendo(t, TreeRight(a), n, ret);
	}
}

bool CheckSumN(const Node* t, int n)
{
	if (TreeIsLeaf(t))
	{
		return false;
	}
	bool ret = false;

	FissaPrimoAddendo(t, t, n, &ret);

	return ret;
	
}