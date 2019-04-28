#ifndef LISTA_CPP
#define LISTA_CPP

#include "Item.h"

template <class T>
Item<T>::Item() = default;

template <class T>
Item<T>::~Item() = default;

template <class T>
void Item<T>::setTipo(T* tipo) {
    this->tipo = tipo;
}

template <class T>
T* Item<T>::getTipo() {
    return tipo;
}

template <class T>
void Item<T>::setProximo(Item* proximo) {
    this->proximo = proximo;
}

template <class T>
Item<T>* Item<T>::getProximo() {
    return proximo;
}

template <class T>
void Item<T>::setAnterior(Item<T>* anterior) {
    this->anterior = anterior;
}

template <class T>
Item<T>* Item<T>::getAnterior() {
    return anterior;
}

#endif
