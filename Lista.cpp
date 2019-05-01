#ifndef LISTA_CPP
#define LISTA_CPP

#include "Lista.h"
#include "Curso.h"
#include "Pessoa.h"

template <class T>
Lista<T>::Lista() {
    this->head = nullptr;
    this->tail = nullptr;
    this->tamanho = 0;
}

template <class T>
Lista<T>::~Lista() = default;

template <class T>
void Lista<T>::insereInicio(T* tipo) {
    Item<T>* item = new Item<T>();
    item->setTipo(tipo);
    item->setProximo(nullptr);
    item->setAnterior(nullptr);

    if (this->head == nullptr) {
        this->head = item;
        this->tail = item;
    }
    else {
        item->setProximo(this->head);

        this->head->setAnterior(item);
        this->head = item;
    }

    this->tamanho++;
}

template <class T>
void Lista<T>::insereFim(T* tipo) {
    Item<T>* item = new Item<T>();
    item->setTipo(tipo);
    item->setProximo(nullptr);
    item->setAnterior(nullptr);

    if (this->head == nullptr) {
        this->head = item;
        this->tail = item;
    }
    else {
        item->setAnterior(this->tail);

        this->tail->setProximo(item);
        this->tail = item;
    }

    this->tamanho++;
}

template <class T>
void Lista<T>::insereApos(Item<T>* itemAnterior, T* tipo) {
    Item<T>* item = new Item<T>();
    item->setTipo(tipo);
    item->setProximo(nullptr);
    item->setAnterior(nullptr);

    Item<T>* auxiliar = itemAnterior->getProximo();

    itemAnterior->setProximo(item);

    item->setProximo(auxiliar);
    item->setAnterior(itemAnterior);

    this->tamanho++;
}

template <class T>
void Lista<T>::retira(Item<T>* item) {
    Item<T>* anterior = item->getAnterior();
    Item<T>* proximo = item->getProximo();

    if (item == this->head)
        this->head = proximo;

    if (item == this->tail)
        this->tail = anterior;

    if (anterior != nullptr)
        anterior->setProximo(proximo);

    if (proximo != nullptr)
        proximo->setAnterior(anterior);

    this->tamanho--;

    if (this->tamanho == 0) {
        this->head = nullptr;
        this->tail = nullptr;
    }

}

template <class T>
Item<T>* Lista<T>::getHead() {
    return head;
}

template <class T>
Item<T>* Lista<T>::getTail() {
    return tail;
}

template <class T>
int Lista<T>::getTamanho() {
    return this->tamanho;
}

template class Lista<Curso>;
template class Lista<Pessoa>;

#endif
