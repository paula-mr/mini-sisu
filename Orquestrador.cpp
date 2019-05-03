#ifndef PESSOA_CPP
#define PESSOA_CPP

#include "Orquestrador.h"

Lista<Curso>* Orquestrador::lerCursos(int quantidadeCursos) {
    Lista<Curso>* cursos = new Lista<Curso>();

    for (int i=0; i<quantidadeCursos; i++) {
        std::string nome;
        int quantidadeVagas;
        Curso* curso = new Curso();

        std::getline(std::cin >> std::ws, nome);
        std::cin >> quantidadeVagas;

        curso->setNome(nome);
        curso->setQuantidadeVagas(quantidadeVagas);

        cursos->insereFim(curso);
    }

    return cursos;
}


Lista<Pessoa>* Orquestrador::lerPessoas(int quantidadeAlunos, Lista<Curso>* cursos) {
    Lista<Pessoa>* pessoas = new Lista<Pessoa>();

    for (int i=0; i<quantidadeAlunos; i++) {
        std::string nome;
        float nota;
        int primeiraOpcao, segundaOpcao;
        Pessoa* pessoa = new Pessoa();

        std::getline(std::cin >> std::ws, nome);
        std::cin >> nota >> primeiraOpcao >> segundaOpcao;

        pessoa->setNome(nome);
        pessoa->setNota(nota);
        pessoa->setPrimeiraOpcao(primeiraOpcao);
        pessoa->setSegundaOpcao(segundaOpcao);

        pessoas->insereFim(pessoa);

        Curso* cursoPrimeiraOpcao = Curso::recuperarPorCodigo(cursos, primeiraOpcao);
        Curso* cursoSegundaOpcao = Curso::recuperarPorCodigo(cursos, segundaOpcao);

        cursoPrimeiraOpcao->inserirEspera(pessoa);
        cursoSegundaOpcao->inserirEspera(pessoa);

    }

    return pessoas;
}

void Orquestrador::calcularAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas) {

    Item<Curso>* itemCurso = cursos->getHead();

    while (itemCurso != nullptr) {
        Curso* curso = itemCurso->getTipo();
        curso->calcularAprovados();

        itemCurso = itemCurso->getProximo();
    }
}

void Orquestrador::removerDuplicacaoAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas) {
    Item<Pessoa>* item = pessoas->getHead();

    while (item != nullptr) {
        Curso::validarAprovadosDoisCursos(cursos, item);
        item = item->getProximo();
    }
}

void Orquestrador::imprimirCursos(Lista<Curso>* cursos) {
    Item<Curso>* item = cursos->getHead();

    while (item != nullptr) {
        Curso* curso = item->getTipo();

        std::cout << curso->getNome() << " " << curso->getNotaCorte()
                << "\nClassificados\n";

        imprimirPessoas(curso->getAprovados());

        std::cout << "Lista de espera\n";

        imprimirPessoas(curso->getEspera());

        if (item->getProximo() != nullptr)
            std::cout << "\n";

        item = item->getProximo();
    }
}

void Orquestrador::imprimirPessoas(Lista<Pessoa>* pessoas) {
    Item<Pessoa>* item = pessoas->getHead();

    while (item != nullptr) {
        Pessoa* pessoa = item->getTipo();
        std::cout << pessoa->getNome() << " "
                    << pessoa->getNota() << "\n";

        item = item->getProximo();
    }
}


#endif
