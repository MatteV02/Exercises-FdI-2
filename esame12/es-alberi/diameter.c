#include "tree.h"

static int Altezza(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}

	int ret = 1;

	int altezza_sinistra = Altezza(TreeLeft(t));
	int altezza_destra = Altezza(TreeRight(t));

	if (altezza_sinistra >= altezza_destra)
	{
		ret += altezza_sinistra;
	}
	else {
		ret += altezza_destra;
	}

	return ret;
}

int Diameter(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}

	int diametro_sinistro = Diameter(TreeLeft(t));
	int diametro_destro = Diameter(TreeRight(t));
	int percorso_piu_lungo = Altezza(TreeLeft(t)) + Altezza(TreeRight(t)) + 1;

	if (diametro_sinistro >= diametro_destro && diametro_sinistro >= percorso_piu_lungo)
	{
		return diametro_sinistro;
	}

	if (diametro_destro >= diametro_sinistro && diametro_destro >= percorso_piu_lungo)
	{
		return diametro_destro;
	}

	return percorso_piu_lungo;
}