#include "tree.h"

int TrovaMin(const ElemType* v, int start, int end)
{
	int ret = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (ElemCompare(v + i, v + ret) < 0)
		{
			ret = i;
		}
	}

	return ret;
}

Node* CreateMinBinRec(const ElemType* v, int start, int end)
{
	if (start > end)
	{
		return TreeCreateEmpty();
	}

	int min = TrovaMin(v, start, end);

	return TreeCreateRoot(v + min, CreateMinBinRec(v, start, min - 1), CreateMinBinRec(v, min + 1, end));
}

Node* CreateMinBinTree(const ElemType* v, size_t v_size)
{
	return CreateMinBinRec(v, 0, (int)v_size - 1);
}