#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void FrazioneEgiziaRec(int n, int d)
{
	int den_frazione = (int)ceil((double)d / n);
	printf("1/%d", den_frazione);
	if (d % n != 0) {
		//continua

		printf(" + ");
		FrazioneEgiziaRec(n * den_frazione - d, d * den_frazione); // sottrazione tra frazioni
	}
}

void FrazioneEgizia(int n, int d)
{
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
	}
	else {
		FrazioneEgiziaRec(n, d);
	}
}