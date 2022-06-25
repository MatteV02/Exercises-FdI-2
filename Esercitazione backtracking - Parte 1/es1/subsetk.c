#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void SubsetKRec(int n, int k, int i, bool v_curr[], int *n_sol, int n_elem)
{

	if (n_elem == k) {
		
		++(*n_sol);
		printf("{ ");
		for (int j = 0; j < i; j++) {

			if (v_curr[j]) {
				printf("%d ", j);
			}

		}

		printf("%d }, ", i);
		
		return;
	}

	if (i == n) {
		return;
	}

	v_curr[i] = false;
	SubsetKRec(n, k, i + 1, v_curr, n_sol, n_elem);
	
	v_curr[i] = true;
	SubsetKRec(n, k, i + 1, v_curr, n_sol, n_elem + 1);
	
	v_curr[i] = false; // Rollback

}

int SubsetK(int n, int k)	// numero elementi nell'insieme
{
	bool* sol = calloc(n, sizeof(bool));
	int n_sol = 0;

	SubsetKRec(n, k, 0, sol, &n_sol, 0);

	free(sol);
	return n_sol;
}

int main(void)
{
	int n_sol = SubsetK(4, 2);
	return EXIT_SUCCESS;
}