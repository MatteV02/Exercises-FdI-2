#if !defined DOMINO_H_
#define DOMINO_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t val1;
    uint8_t val2;
} Tessera;
typedef struct {
    uint32_t indice;
    bool flipped;
} Placing;

extern Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size);

#endif // !defined DOMINO_H_
