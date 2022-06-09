#include <stdlib.h>
#include <float.h>

#include "tree.h"

static size_t ContaElementiBst(const Node* t) {
	size_t ret = 0;

	if (!TreeIsEmpty(t)) {
		ret = 1;
		ret += ContaElementiBst(TreeLeft(t));
		ret += ContaElementiBst(TreeRight(t));
	}

	return ret;
}

static void ElemNodeIRec(const Node* t, size_t* i, size_t i_el, const ElemType** ret) {
	if (*ret == NULL) {
		
		if (!TreeIsEmpty(TreeLeft(t))) {
			ElemNodeIRec(TreeLeft(t), i, i_el, ret);
		}
		++(*i);

		if (*i == i_el) {
			*ret = TreeGetRootValue(t);
		}

		if (*i >= i_el) {
			return;
		}

		if (!TreeIsEmpty(TreeRight(t))) {
			ElemNodeIRec(TreeRight(t), i, i_el, ret);
		}

	}
}

static const ElemType* ElemNodeI(const Node* t, size_t i_el) 
{
	const ElemType* ret = NULL;

	size_t i = 0;

	ElemNodeIRec(t, &i, i_el, &ret);

	return ret;
}

double Mediano(const Node* t)
{
	double ret = DBL_MAX;

	size_t t_dim = ContaElementiBst(t);

	if (t_dim != 0) {
		if (t_dim % 2 != 0) {
			ret = (double)(*ElemNodeI(t, t_dim / 2 + 1));
		}
		else {
			double a = (double)(*ElemNodeI(t, t_dim / 2));
			double b = (double)(*ElemNodeI(t, t_dim / 2 + 1));

			ret = (a + b) / 2;
		}
	}

	return ret;
}