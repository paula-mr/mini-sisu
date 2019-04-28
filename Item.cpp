#ifndef LISTA_CPP
#define LISTA_CPP

#include "Item.h"
#include "Curso.h"

template <class T>
Item<T>::Item() = default;

template <class T>
Item<T>::~Item() = default;

template <class T>
void Item<T>::setTipo(T* tipo) {
    this->tipo = tipo;
}

template <class T>
<T>* Item::getTipo() {
    return tipo;
}

void Item::setProximo(Item* proximo) {
    this->proximo = proximo;
}

Item* Item::getProximo() {
    return proximo;
}

void Item::setAnterior(Item* anterior) {
    this->anterior = anterior;
}

Item* Item::getAnterior() {
    return anterior;
}

template class Item<Curso>;

#endif
