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
        bool itemInserido = false;

        if (Pessoa::compararColocacao(espera->getHead()->getTipo(), pessoa, this->codigo) < 0) {
            espera->insereInicio(pessoa);
            itemInserido = true;
        }

        if (Pessoa::compararColocacao(espera->getTail()->getTipo(), pessoa, this->codigo) > 0) {
            espera->insereFim(pessoa);
            itemInserido = true;
        }

        Item<Pessoa>* item = espera->getHead();
        Item<Pessoa>* itemAnterior = nullptr;

        while (item != nullptr && !itemInserido) {

            if (Pessoa::compararColocacao(item->getTipo(), pessoa, this->codigo) > 0) {
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

Curso* Curso::recuperarPorCodigo(Lista<Curso>* cursos, int codigo) {
    Item<Curso>* item = cursos->getHead();

    while (item != nullptr) {
        Curso* curso = item->getTipo();

        if (curso->getCodigo() == codigo)
            return curso;

        item = item->getProximo();
    }

    return nullptr;
}

void Curso::calcularAprovados() {
    Item<Pessoa>* item = this->espera->getHead();

    for (int i=0; i < this->quantidadeVagas; i++) {
        Pessoa* pessoa = item->getTipo();
        this->aprovados->insereFim(pessoa);

        pessoa->setAprovadaCurso(this->codigo);

        item = item->getProximo();

        this->espera->retira(item->getAnterior());
    }
}

#endif
