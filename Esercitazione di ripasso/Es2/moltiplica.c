#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int ret = 0;
	
	if (argc == 3) {
		int f1 = strtol(argv[1], NULL, 10);
		int f2 = strtol(argv[2], NULL, 10);

		printf("%d", f1 * f2);
	}
	else {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> <b>\"");
		ret = 1;
	}

	return ret;
}