#ifndef ORQUESTRADOR_H
#define ORQUESTRADOR_H

#include <string>
#include <iomanip>

#include "Lista.h"
#include "Curso.h"
#include "Pessoa.h"

class Orquestrador {
    public:
        static Lista<Curso>* lerCursos(int quantidadeCursos);
        static Lista<Pessoa>* lerPessoas(int quantidadeAlunos, Lista<Curso>* cursos);
        static void calcularAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);
        static void removerDuplicacaoAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);

        static void imprimirCursos(Lista<Curso>* cursos);
        static void imprimirPessoas(Lista<Pessoa>* pessoas);
};

#endif
