#if !defined TORRE_CARTONI_H_
#define TORRE_CARTONI_H_

#include <stdlib.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);\

#endif // !defined TORRE_CARTONI_H_
