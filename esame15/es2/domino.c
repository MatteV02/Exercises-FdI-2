#include "domino.h"

#include <string.h>

void DominoRec(const Tessera* t, size_t i, size_t t_size, Placing* vcurr, bool *presi, Placing* best, size_t* best_size, uint8_t prev)
{
	if (*best_size == t_size)
	{
		return;
	}

	if (i < t_size) {

		for (size_t j = 0; j < t_size; ++j)
		{
			if (!presi[j]) {

				if (prev == 0 || t[j].val1 == prev) {
					presi[j] = true;

					vcurr[i] = (Placing){ (uint32_t)j, false };
					DominoRec(t, i + 1, t_size, vcurr, presi, best, best_size, t[j].val2);
					
					presi[j] = false;
				}

				if (prev == 0 || t[j].val2 == prev) {
					presi[j] = true;

					vcurr[i] = (Placing){ (uint32_t)j, true };
					DominoRec(t, i + 1, t_size, vcurr, presi, best, best_size, t[j].val1);
					
					presi[j] = false;
				}

			}
		}
	}

	if (i > *best_size) {
		memcpy(best, vcurr, sizeof(Placing) * (i));
		*best_size = i;
	}
}

Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size)
{
	Placing* vcurr = malloc(sizeof(Placing) * t_size),
		* best = malloc(sizeof(Placing) * t_size);
	size_t best_size = 0;
	bool* presi = calloc(t_size, sizeof(bool));

	DominoRec(t, 0, t_size, vcurr, presi, best, &best_size, 0);

	free(vcurr); free(presi);
	*ret_size = best_size;
	return best;
}