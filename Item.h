#ifndef ITEM_H
#define ITEM_H

#include <iostream>

template <class T>

class Item {
    private:
        T* tipo;
        Item<T>* anterior;
        Item<T>* proximo;

    public:
        Item();
        ~Item();
        void setTipo(T* tipo);
        T* getTipo();
        void setProximo(Item<T>* proximo);
        Item<T>* getProximo();
        void setAnterior(Item<T>* anterior);
        Item<T>* getAnterior();
};

#endif
