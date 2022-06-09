#include <stdlib.h>
#include <stdio.h>

void StampaRec(int n)
{
	if (n >= 2) {
		StampaRec(n / 2);
	}

	printf("%d", n % 2);
	return;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1;
	}

	int n;

	n = strtol(argv[1], NULL, 10);

	if (n < 0) {
		return 1;
	}

	StampaRec(n);

	return 0;
}