#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "Curso.h"
#include "Pessoa.h"

template <class T>

class Item {
    private:
        T* tipo;
        Item* anterior;
        Item* proximo;

    public:
        Item();
        ~Item();
        void setTipo(T* tipo);
        T* getTipo();
        void setProximo(Item* proximo);
        Item* getProximo();
        void setAnterior(Item* anterior);
        Item* getAnterior();
};

template class Item<Curso>;
template class Item<Pessoa>;

#endif
