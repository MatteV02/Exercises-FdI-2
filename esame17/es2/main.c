#include <stdlib.h>

extern int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size);

int main(void)
{
	int bam[] = { 5, 10, 15, 20, 25, 30, 35 },
		bis[] = { 32, 29, 10, 7, 29, 3, 11, 23 };
	size_t bam_size = sizeof(bam) / sizeof(*bam),
		bis_size = sizeof(bis) / sizeof(*bis);

	int n_bambini_soddisfatti = AssegnaBiscotti(bam, bam_size, bis, bis_size);

	return 0;
}