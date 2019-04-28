#ifndef CURSO_CPP
#define CURSO_CPP

#include "Curso.h"

Curso::Curso() = default;
Curso::~Curso() = default;

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
