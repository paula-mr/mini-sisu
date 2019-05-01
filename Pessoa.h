#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

#include "Item.h"
#include "Lista.h"

class Pessoa {
    private:
        int codigo;
        std::string nome;
        float nota;
        int primeiraOpcao;
        int segundaOpcao;
        static int contador;
        bool aprovadaPrimeiraOpcao;
        bool aprovadaSegundaOpcao;

    public:
        Pessoa();
        ~Pessoa();
        int getCodigo();
        void setNome(std::string nome);
        std::string getNome();
        void setNota(float nota);
        float getNota();
        void setPrimeiraOpcao(int opcao);
        int getPrimeiraOpcao();
        void setSegundaOpcao(int opcao);
        int getSegundaOpcao();
        bool isAprovadaPrimeiraOpcao();
        void setAprovadaPrimeiraOpcao();
        bool isAprovadaSegundaOpcao();
        void setAprovadaSegundaOpcao();

        static int compararColocacao(Pessoa* base, Pessoa* comparacao, int codigoCurso);
        static Item<Pessoa>* recuperarPorCodigo(Lista<Pessoa>* pessoas, int codigo);
};

#endif
