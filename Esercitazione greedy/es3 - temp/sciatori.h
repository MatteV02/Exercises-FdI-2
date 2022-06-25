#if !defined SCIATORI_H_
#define SCIATORI_H_

#include <stdlib.h>

typedef struct {
    double a;
    double l;
} Sciatore;

extern Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size);

#endif // !defined SCIATORI_H_
