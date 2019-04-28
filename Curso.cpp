#ifndef CURSO_CPP
#define CURSO_CPP

#include "Curso.h"

int Curso::contador = 0;

Curso::Curso() {
    this->aprovados = new Lista<Pessoa>();
    this->espera = new Lista<Pessoa>();
    this->codigo = contador;
    contador++;
}

Curso::~Curso() = default;

int Curso::getCodigo() {
    return this->codigo;
}

void Curso::setNome(std::string nome) {
    this->nome = nome;
}

std::string Curso::getNome() {
    return this->nome;
}

void Curso::setQuantidadeVagas(int quantidadeVagas) {
    this->quantidadeVagas = quantidadeVagas;
}

int Curso::getQuantidadeVagas() {
    return this->quantidadeVagas;
}

void Curso::inserirEspera(Pessoa* pessoa) {

    if (espera->getHead() == nullptr) {
        espera->insereFim(pessoa);
    } else {
        Item<Pessoa>* item = espera->getHead();
        Item<Pessoa>* itemAnterior = nullptr;
        bool itemInserido = false;

        while (item != nullptr && !itemInserido) {

            if (Pessoa::compararColocacao(item->getTipo(), pessoa, this->codigo) < 0) {
                espera->insereApos(itemAnterior, pessoa);
                itemInserido = true;
            }

            itemAnterior = item;
            item = item->getProximo();
        }

    }
}

Lista<Pessoa>* Curso::getAprovados() {
    return this->aprovados;
}

Lista<Pessoa>* Curso::getEspera() {
    return this->espera;
}

#endif
