#ifndef LISTA_CPP
#define LISTA_CPP

#include "Lista.h"

Lista::Lista() {
    this->head = nullptr;
}

void Lista::insereFim(Item* item) {
    if (*head == nullptr)
        *head = item;
    else {
        *head.setProximo(item);
        *head.setAnterior0(nullptr);
    }
}

void Lista::retira(Item* item) {
    Item* anterior = item.getAnterior();
    Item* proximo = item.getProximo();

    anterior.setProximo(proximo);
    proximo.setAnterior(anterior);
}

Lista* Lista::getHead() {
    return head;
}

template class Lista<Curso>;

#endif
