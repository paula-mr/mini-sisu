#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "Item.h"
#include "Curso.h"
#include "Pessoa.h"

template <class T>

class Lista {
    private:
        Item<T>* head;

    public:
        Lista();
        ~Lista();
        void insereFim(T* item);
        void insereApos(Item<T>* itemAnterior, T* tipo);
        void retira(Item<T>* item);
        Item<T>* getHead();
};

template class Lista<Curso>;
template class Lista<Pessoa>;

#endif
