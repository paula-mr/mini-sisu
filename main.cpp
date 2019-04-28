#include <string>

#include "Lista.h"

Lista<Curso>* lerCursos(int quantidadeCursos);
void imprimirCursos(Lista<Curso>* cursos);

int main() {
    int quantidadeCursos, quantidadeAlunos;
    Lista<Curso>* cursos;

    std::cin >> quantidadeCursos >> quantidadeAlunos;

    cursos = lerCursos(quantidadeCursos);
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

void imprimirCursos(Lista<Curso>* cursos) {
    Item<Curso>* item = cursos->getHead();

    while (item != nullptr) {
        Curso* curso = item->getTipo();
        std::cout << curso->getNome() << " " << curso->getQuantidadeVagas() << "\n";

        item = item->getProximo();
    }
}
