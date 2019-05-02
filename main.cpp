#include <iomanip>

#include "Orquestrador.h"

int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    int quantidadeCursos, quantidadeAlunos;
    Lista<Curso>* cursos;
    Lista<Pessoa>* pessoas;

    std::cin >> quantidadeCursos >> quantidadeAlunos;

    cursos = Orquestrador::lerCursos(quantidadeCursos);
    pessoas = Orquestrador::lerPessoas(quantidadeAlunos, cursos);

    Orquestrador::calcularAprovados(cursos, pessoas);
    Orquestrador::removerDuplicacaoAprovados(cursos, pessoas);
    Orquestrador::imprimirCursos(cursos);

    return 0;
}
