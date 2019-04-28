#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>

class Curso {
    private:
        std::string nome;
        int quantidadeVagas;

    public:
        Curso();
        ~Curso();
        void setNome(std::string nome);
        std::string getNome();
        void setQuantidadeVagas(int quantidadeVagas);
        int getQuantidadeVagas();
};

#endif
