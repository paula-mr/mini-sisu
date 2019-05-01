#ifndef PESSOA_CPP
#define PESSOA_CPP

#include "Pessoa.h"

int Pessoa::contador = 0;

Pessoa::Pessoa() {
    this->codigo = contador;
    this->aprovadaPrimeiraOpcao = false;
    this->aprovadaSegundaOpcao = false;
    contador++;
}

Pessoa::~Pessoa() = default;

int Pessoa::getCodigo() {
    return this->codigo;
}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}

std::string Pessoa::getNome() {
    return this->nome;
}

void Pessoa::setNota(float nota) {
    this->nota = nota;
}

float Pessoa::getNota() {
    return this->nota;
}
void Pessoa::setPrimeiraOpcao(int opcao) {
    this->primeiraOpcao = opcao;
}

int Pessoa::getPrimeiraOpcao() {
    return this->primeiraOpcao;
}
void Pessoa::setSegundaOpcao(int opcao) {
    this->segundaOpcao = opcao;
}

int Pessoa::getSegundaOpcao() {
    return this->segundaOpcao;
}

bool Pessoa::isAprovadaPrimeiraOpcao() {
    return this->aprovadaPrimeiraOpcao;
}

void Pessoa::setAprovadaCurso(int codigoCurso) {
    if (this->primeiraOpcao == codigoCurso)
        this->aprovadaPrimeiraOpcao = true;
    else if (this->segundaOpcao == codigoCurso)
        this->aprovadaSegundaOpcao = true;
}

bool Pessoa::isAprovadaSegundaOpcao() {
    return this->aprovadaSegundaOpcao;
}

int Pessoa::compararColocacao(Pessoa* base, Pessoa* comparacao, int codigoCurso) {
    const int BASE_MAIOR = 1, BASE_MENOR = -1;

    if (base->getNota() > comparacao->getNota())
        return BASE_MAIOR;

    if (base->getNota() < comparacao->getNota())
        return BASE_MENOR;

    if (base->getPrimeiraOpcao() == codigoCurso && comparacao->getPrimeiraOpcao() != codigoCurso)
        return BASE_MAIOR;

    if (comparacao->getPrimeiraOpcao() == codigoCurso && base->getPrimeiraOpcao() != codigoCurso)
        return BASE_MENOR;

    return base->codigo > comparacao->codigo ? BASE_MENOR : BASE_MAIOR;
}

Item<Pessoa>* Pessoa::recuperarPorCodigo(Lista<Pessoa>* pessoas, int codigo) {
    Item<Pessoa>* item = pessoas->getHead();

    while (item != nullptr) {
        Pessoa* pessoa = item->getTipo();

        if (pessoa->getCodigo() == codigo)
            return item;

        item = item->getProximo();
    }

    return nullptr;
}

#endif

