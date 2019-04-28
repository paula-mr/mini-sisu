#ifndef LISTA_CPP
#define LISTA_CPP

#include "Lista.h"

template <class T>
Lista<T>::Lista() {
    this->head = nullptr;
}

template <class T>
Lista<T>::~Lista() = default;

template <class T>
void Lista<T>::insereFim(T* tipo) {
    Item<T>* item = new Item<T>();
    item->setTipo(tipo);

    if (this->head == nullptr)
        this->head = item;
    else {
        this->head->setProximo(item);
        this->head->setAnterior(nullptr);

        item->setAnterior(head);
        item->setProximo(nullptr);
    }
}

template <class T>
void Lista<T>::retira(Item<T>* item) {
    Item<T>* anterior = item->getAnterior();
    Item<T>* proximo = item->getProximo();

    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);
}

template <class T>
Item<T>* Lista<T>::getHead() {
    return head;
}

#endif
