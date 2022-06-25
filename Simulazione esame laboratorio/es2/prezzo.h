#if !defined PREZZO_H_
#define PREZZO_H_

#include <stdlib.h>

struct Articolo {
    char nome[11];
    int prezzo;
};

extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);

#endif // !defined PREZZO_H_
