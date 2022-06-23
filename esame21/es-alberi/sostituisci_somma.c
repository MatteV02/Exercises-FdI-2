#include "tree.h"

static int Somma(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}

	int somma = t->value;

	somma += Somma(TreeLeft(t));
	somma += Somma(TreeRight(t));

	return somma;
}

void SostituisciSomma(Node* t)
{
	if (TreeIsEmpty(t)) {
		return;
	}

	t->value = Somma(t);

	SostituisciSomma(TreeLeft(t));
	SostituisciSomma(TreeRight(t));
}