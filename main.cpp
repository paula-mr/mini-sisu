#include <string>

#include "Lista.h"
#include "Curso.h"
#include "Pessoa.h"

Lista<Curso>* lerCursos(int quantidadeCursos);
Lista<Pessoa>* lerPessoas(int quantidadeAlunos, Lista<Curso>* cursos);
void calcularAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);
void verificarAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);
void validarAprovado(Lista<Curso>* cursos, Item<Pessoa>* item);

void imprimirCursos(Lista<Curso>* cursos);
void imprimirPessoas(Lista<Pessoa>* pessoas);

int main() {
    int quantidadeCursos, quantidadeAlunos;
    Lista<Curso>* cursos;
    Lista<Pessoa>* pessoas;

    std::cin >> quantidadeCursos >> quantidadeAlunos;

    cursos = lerCursos(quantidadeCursos);
    pessoas = lerPessoas(quantidadeAlunos, cursos);

    calcularAprovados(cursos, pessoas);
    verificarAprovados(cursos, pessoas);
    imprimirCursos(cursos);

    return 0;
}

Lista<Curso>* lerCursos(int quantidadeCursos) {
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


Lista<Pessoa>* lerPessoas(int quantidadeAlunos, Lista<Curso>* cursos) {
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

void calcularAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas) {
    Item<Curso>* itemCurso = cursos->getHead();

    while (itemCurso != nullptr) {
        Curso* curso = itemCurso->getTipo();
        curso->calcularAprovados();

        itemCurso = itemCurso->getProximo();
    }
}

void verificarAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas) {
    Item<Pessoa>* item = pessoas->getHead();

    while (item != nullptr) {
        validarAprovado(cursos, item);

        item = item->getProximo();
    }
}

void validarAprovado(Lista<Curso>* cursos, Item<Pessoa>* item) {
    Pessoa* pessoa = item->getTipo();

    if (pessoa->isAprovadaPrimeiraOpcao()) {
        if(pessoa->isAprovadaSegundaOpcao()) {
            Curso* segundaOpcao = Curso::recuperarPorCodigo(cursos, pessoa->getSegundaOpcao());

            Item<Pessoa>* novoAprovado = segundaOpcao->getEspera()->getHead();
            segundaOpcao->getEspera()->retira(novoAprovado);
            segundaOpcao->getAprovados()->insereFim(novoAprovado->getTipo());

            Item<Pessoa>* aprovadoPrimeiraOpcao = Pessoa::recuperarPorCodigo(segundaOpcao->getAprovados(), pessoa->getCodigo());
            segundaOpcao->getAprovados()->retira(aprovadoPrimeiraOpcao);

            novoAprovado->getTipo()->setAprovadaCurso(segundaOpcao->getCodigo());

            validarAprovado(cursos, novoAprovado);

        } else {
            Curso* segundaOpcao = Curso::recuperarPorCodigo(cursos, pessoa->getSegundaOpcao());
            segundaOpcao->getEspera()->retira(item);
        }
    }
}

void imprimirCursos(Lista<Curso>* cursos) {
    Item<Curso>* item = cursos->getHead();

    while (item != nullptr) {
        Curso* curso = item->getTipo();
        Pessoa* ultimoAprovado = curso->getAprovados()->getTail()->getTipo();

        std::cout << "\n" << curso->getNome() << " " << ultimoAprovado->getNota()
                << "\nClassificados\n";

        imprimirPessoas(curso->getAprovados());

        std::cout << "Lista de espera\n";

        imprimirPessoas(curso->getEspera());

        std::cout << "\n";

        item = item->getProximo();
    }
}

void imprimirPessoas(Lista<Pessoa>* pessoas) {
    Item<Pessoa>* item = pessoas->getHead();

    while (item != nullptr) {
        Pessoa* pessoa = item->getTipo();
        std::cout << pessoa->getNome() << " "
                    << pessoa->getNota() << "\n";

        item = item->getProximo();
    }
}
