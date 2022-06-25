#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int ret = 1;
	if (argc == 3) {
		char c = argv[2][0];
		int count = 0;
		for (size_t i = 0; argv[1][i] != 0; i++) {
			if (argv[1][i] == c) {
				count++;
			}
		}
		printf("%d", count);
		ret = 0;
	}
	else {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorenze <s> <c>\"");
	}

	return ret;
}