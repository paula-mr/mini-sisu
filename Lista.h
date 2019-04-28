#ifndef LISTA_H
#define LISTA_H

#include "Item.h"
#include "Curso.h"

template <class T>

class Lista {
    private:
        Item<T>* head;

    public:
        Lista();
        void insereFim(Item<T>* item);
        void retira(Item<T>* item);
        Item<T>* getHead();
};

template class Lista<Curso>;

#endif
