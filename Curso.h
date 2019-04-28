#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>

class Curso {
    private:
        int codigo;
        std::string nome;
        int quantidadeVagas;
        static int contador;

    public:
        Curso();
        ~Curso();
        int getCodigo();
        void setNome(std::string nome);
        std::string getNome();
        void setQuantidadeVagas(int quantidadeVagas);
        int getQuantidadeVagas();
};

#endif
