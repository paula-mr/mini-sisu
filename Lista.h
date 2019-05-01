#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "Item.h"

template <class T>

class Lista {
    private:
        Item<T>* head;
        Item<T>* tail;

    public:
        Lista();
        ~Lista();
        void insereInicio(T* tipo);
        void insereFim(T* tipo);
        void insereApos(Item<T>* itemAnterior, T* tipo);
        void retira(Item<T>* tipo);
        Item<T>* getHead();
        Item<T>* getTail();
};

#endif
