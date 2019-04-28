#ifndef LISTA_H
#define LISTA_H

#include <iostream>

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

#endif
