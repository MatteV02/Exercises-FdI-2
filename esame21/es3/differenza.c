#include "list.h"

static Item* ListCopy(const Item* i) {
    Item* list_copy = ListCreateEmpty(); // Creo una lista vuota (NULL pointer)

    // Itero tutti gli elementi della lista da copiare
    for (; !ListIsEmpty(i); i = ListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = ListInsertBack(list_copy, ListGetHeadValue(i));
    }

    return list_copy;
}

static Item* DifferenzaRec(const Item* i1, const Item* i2, int prestito)
{
    if (ListIsEmpty(i1)) {
        return ListCreateEmpty();
    }

    if (ListIsEmpty(i2))
    {
        char temp = i1->value + prestito;
        Item* ret = ListInsertHead(&temp, ListCopy(i1->next));
        return ret;
    }
    
    char diff = i1->value - i2->value + prestito + '0';
    
    prestito = 0;
    if (diff < '0') {
        prestito = -1;
        diff += 10;
    }

    return ListInsertHead(&diff, DifferenzaRec(ListGetTail(i1), ListGetTail(i2), prestito));
}

Item* Differenza(const Item* i1, const Item* i2)
{
    return DifferenzaRec(i1, i2, 0);
}