#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "minheap.h"

extern bool HeapMinPop(Heap* h, ElemType* e);

Heap* HeapifyMinHeap(const ElemType* v, size_t v_size) {
    // Costruisco la heap con gli elementi del vettore v
    Heap* h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * (v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    // Chiamo la HeapMinMoveDown a partire dai nodi nel penultimo livello
    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
    // le proprietà (min-)heap. Non serve chiamare la HeapMinMoveDown sulle
    // foglie perché non avrebbe alcun effetto.
    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMinMoveDown(h, i);
    }
    return h;
}

int main(void)
{
    ElemType v[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };
    Heap* h = HeapifyMinHeap(v, sizeof(v)/sizeof(*v));

    ElemType ret;

    HeapMinPop(h, &ret);

    HeapDelete(h);

	return 0;
}