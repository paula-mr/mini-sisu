#ifndef CURSO_CPP
#define CURSO_CPP

#include "Curso.h"

int Curso::contador = 0;

Curso::Curso() {
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

#endif
