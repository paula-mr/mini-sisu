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

float Curso::getNotaCorte() {
    Item<Pessoa>* ultimoAprovado = this->getAprovados()->getTail();

    float notaCorte = ultimoAprovado == nullptr ? 0 : ultimoAprovado->getTipo()->getNota();
    notaCorte = this->getAprovados()->getTamanho() == this->quantidadeVagas ? notaCorte : 0;

    return notaCorte;
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

void Curso::validarAprovadosDoisCursos(Lista<Curso>* cursos, Item<Pessoa>* item) {
    Pessoa* pessoa = item->getTipo();

    if (pessoa->isAprovadaPrimeiraOpcao()) {
        if(pessoa->isAprovadaSegundaOpcao()) {
            Curso* segundaOpcao = Curso::recuperarPorCodigo(cursos, pessoa->getSegundaOpcao());

            Item<Pessoa>* aprovadoPrimeiraOpcao = Pessoa::recuperarPorCodigo(segundaOpcao->getAprovados(), pessoa->getCodigo());
            segundaOpcao->getAprovados()->retira(aprovadoPrimeiraOpcao);

            Item<Pessoa>* novoAprovado = segundaOpcao->getEspera()->getHead();

            if (novoAprovado != nullptr && segundaOpcao->getAprovados()->getTamanho()
                                            < segundaOpcao->getQuantidadeVagas()) {
                segundaOpcao->getEspera()->retira(novoAprovado);
                segundaOpcao->getAprovados()->insereFim(novoAprovado->getTipo());
                novoAprovado->getTipo()->setAprovadaCurso(segundaOpcao->getCodigo());
                validarAprovadosDoisCursos(cursos, novoAprovado);
            }

        } else {
            Curso* segundaOpcao = Curso::recuperarPorCodigo(cursos, pessoa->getSegundaOpcao());
            Item<Pessoa>* aprovadoPrimeiraOpcao = Pessoa::recuperarPorCodigo(segundaOpcao->getEspera(), pessoa->getCodigo());
            segundaOpcao->getEspera()->retira(aprovadoPrimeiraOpcao);

        }
    }
}

void Curso::calcularAprovados() {
    Item<Pessoa>* item = this->espera->getHead();

    while(this->aprovados->getTamanho() < this->quantidadeVagas && item != nullptr) {
        Pessoa* pessoa = item->getTipo();
        this->aprovados->insereFim(pessoa);

        pessoa->setAprovadaCurso(this->codigo);

        this->espera->retira(item);
        item = item->getProximo();

    }
}

#endif
