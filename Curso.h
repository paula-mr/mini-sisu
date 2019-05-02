#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>

#include "Lista.h"
#include "Pessoa.h"

class Curso {
    private:
        int codigo;
        std::string nome;
        int quantidadeVagas;
        Lista<Pessoa>* aprovados;
        Lista<Pessoa>* espera;
        static int contador;

    public:
        Curso();
        ~Curso();
        int getCodigo();
        void setNome(std::string nome);
        std::string getNome();
        void setQuantidadeVagas(int quantidadeVagas);
        int getQuantidadeVagas();
        float getNotaCorte();
        void inserirEspera(Pessoa* pessoa);
        Lista<Pessoa>* getAprovados();
        Lista<Pessoa>* getEspera();
        void calcularAprovados();

        static void validarAprovadosDoisCursos(Lista<Curso>* cursos, Item<Pessoa>* item);
        static Curso* recuperarPorCodigo(Lista<Curso>* cursos, int codigo);
};

#endif
