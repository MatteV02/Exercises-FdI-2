#if !defined TORRECARTONI_H_
#define TORRECARTONI_H_

#include <stdlib.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);

#endif // !defined TORRECARTONI_H_


