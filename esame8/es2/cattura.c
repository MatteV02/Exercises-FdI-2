#include <stdlib.h>
#include <string.h>

#if defined WIN32 & _DEBUG
#include <crtdbg.h>
#endif // defined WIN32

void CacciatorePredaRec(const char* v, size_t v_size, int u, int* vcurr, int vcurr_prese, const int* cacciatori_pos,
	int cacciatori_size, int i, int* best, int* best_prese)
{
	if (i == cacciatori_size) {
		//caso base

		if (vcurr_prese > *best_prese)
		{
			memcpy(best, vcurr, sizeof(*vcurr) * v_size);
			*best_prese = vcurr_prese;
		}
	}
	else {
		vcurr[cacciatori_pos[i]] = -1;

		CacciatorePredaRec(v, v_size, u, vcurr, vcurr_prese, cacciatori_pos, cacciatori_size, i + 1, best, best_prese);	//i+1

		for (int j = cacciatori_pos[i] - u; j <= cacciatori_pos[i] + u; ++j) {
			if (j < 0 || j >= (int)v_size) {
				//skippa
				continue;
			}

			switch (v[j])
			{
			case 'P': case 'p':
				if (vcurr[j] == -1) {
					vcurr[j] = -2;
					vcurr[cacciatori_pos[i]] = j;

					CacciatorePredaRec(v, v_size, u, vcurr, vcurr_prese + 1, cacciatori_pos, cacciatori_size, i + 1, best, best_prese); //i+1, vcurr_prese + 1

					vcurr[j] = -1;
				}
				break;
			default:
				break;
			}
		}
	}
}

int* CacciatorePreda(const char* v, size_t v_size, int u)
{
	int* vcurr = malloc(sizeof(*vcurr) * v_size), * best = malloc(sizeof(*best) * v_size);
	memset(best, -1, sizeof(*best) * v_size);
	int best_prese = 0;
	int* cacciatori_pos = NULL;
	int cacciatori_size = 0;

	for (int i = 0; i < (int)v_size; i++)
	{
		switch (v[i])
		{
		case 'C': case 'c':
			cacciatori_pos = realloc(cacciatori_pos, sizeof(*cacciatori_pos) * (cacciatori_size + 1));
			cacciatori_pos[cacciatori_size] = i;
			++cacciatori_size;
			break;
		case 'P': case 'p':
			vcurr[i] = -1;
			break;
		default:
			break;
		}
	}

	CacciatorePredaRec(v, v_size, u, vcurr, 0, cacciatori_pos, cacciatori_size, 0, best, &best_prese);

	free(cacciatori_pos); free(vcurr);

	return best;
}