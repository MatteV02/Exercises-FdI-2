#if !defined COLORA_H_
#define COLORA_H_

#include <stdlib.h>
#include <stdbool.h>

struct Matrix {
    size_t size;
    bool* data;
};

extern int MappaColori(const struct Matrix* m, const char* c, size_t c_size);

#endif // !defined COLORA_H_
