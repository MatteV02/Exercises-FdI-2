#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


static void BabboNataleRec(const int* pacchi, const size_t pacchi_size, const int p, size_t i, int *max_pacchi, int p_att, int n_pacchi, bool vsol[], bool sol_migliore[]) 
{

	if (p_att > p || (int)pacchi_size - (int)i < *max_pacchi - n_pacchi) {
		return;
	}

	if (i == pacchi_size) {
		if (n_pacchi >= *max_pacchi) {
			for (size_t j = 0; j < pacchi_size; j++) {
				sol_migliore[j] = vsol[j];
			}
			*max_pacchi = n_pacchi;
		}
		return;
	}

	vsol[i] = true;
	p_att += pacchi[i];
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, max_pacchi, p_att, n_pacchi + 1, vsol, sol_migliore);

	p_att -= pacchi[i];
	vsol[i] = false;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, max_pacchi, p_att, n_pacchi, vsol, sol_migliore);

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p)
{
	bool* vsol = malloc(sizeof(bool) * pacchi_size);
	bool* sol_migliore = calloc(pacchi_size, sizeof(bool));
	int max_pacchi = 0;

	int temp = 0;

	BabboNataleRec(pacchi, pacchi_size, p, 0, &max_pacchi, 0, 0, vsol, sol_migliore);

	for (size_t i = 0; i < pacchi_size; i++) 
	{
		if (sol_migliore[i]) {
			printf("1 ");
			temp += pacchi[i];
		}
		else {
			printf("0 ");
		}
	}

	free(vsol);
	free(sol_migliore);

}