#include <stdlib.h>
#include <string.h>

int CercaBambino(const int* bam_cpy, size_t bam_size, int peso_biscotto)
{
    int ret = -1;
    int diff_abs_min;
    for (size_t i = 0; i < bam_size; ++i)
    {
        if (bam_cpy[i] > 0 && (ret == -1 || abs(peso_biscotto - bam_cpy[i]) < diff_abs_min))
        {
            ret = i;
            diff_abs_min = abs(peso_biscotto - bam_cpy[i]);
        }
    }

    if (ret > 0 && bam_cpy[ret] - peso_biscotto > 0) {
        int ret_temp = -1;
        for (size_t i = 0; i < bam_size; ++i)
        {
            if (bam_cpy[i] > 0 && (ret_temp == -1 || (bam_cpy[i] - peso_biscotto <= 0 && abs(peso_biscotto - bam_cpy[i]) < diff_abs_min)))
            {
                ret_temp = i;
                diff_abs_min = abs(peso_biscotto - bam_cpy[i]);
            }
        }
        if (ret_temp != -1)
        {
            ret = ret_temp;
        }
    }

    return ret;
}

int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size)
{
    if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0)
    {
        return 0;
    }

    int* bam_cpy = memcpy(malloc(sizeof(*bam_cpy) * bam_size), bam, sizeof(*bam_cpy) * bam_size);

    int n_bambini_soddisfatti = 0;

    for (size_t i = 0; i < bis_size; ++i)
    {
        int b_attuale = CercaBambino(bam_cpy, bam_size, bis[i]);
        if (b_attuale < 0) {
            break;
        }

        bam_cpy[b_attuale] -= bis[i];
        if (bam_cpy[b_attuale] <= 0)
        {
            n_bambini_soddisfatti++;
        }
    }

    free(bam_cpy);

    return n_bambini_soddisfatti;
}