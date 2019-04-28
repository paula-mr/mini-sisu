#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

class Pessoa {
    private:
        int codigo;
        std::string nome;
        float nota;
        int primeiraOpcao;
        int segundaOpcao;
        static int contador;

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

        static int compararColocacao(Pessoa* base, Pessoa* comparacao, int codigoCurso);
};

#endif
