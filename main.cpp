#include <iomanip>

#include "Orquestrador.h"

Lista<Curso>* lerCursos(int quantidadeCursos);
Lista<Pessoa>* lerPessoas(int quantidadeAlunos, Lista<Curso>* cursos);
void calcularAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);
void removerDuplicacaoAprovados(Lista<Curso>* cursos, Lista<Pessoa>* pessoas);

void imprimirCursos(Lista<Curso>* cursos);
void imprimirPessoas(Lista<Pessoa>* pessoas);

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
