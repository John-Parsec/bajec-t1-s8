#include "Tarefas.hpp"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    const string nomeArquivo = "../bd.txt";

    GerenciadorTarefas gerenciadorTarefas;
    BancoDeDados::carregarTarefas(nomeArquivo, &gerenciadorTarefas);

    
}