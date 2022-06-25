#if !defined GIOIELLI_H_
#define GIOIELLI_H_

#include <stdlib.h>

typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);

#endif // !defined GIOIELLI_H_
