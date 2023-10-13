#include "Tarefas.hpp"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    const string nomeArquivo = "bd.txt";

    GerenciadorTarefas gerenciadorTarefas;
    BancoDeDados::carregarTarefas(nomeArquivo, &gerenciadorTarefas);

    bool check = 1;
    int acao;
    while(check)
    {
        cout << endl << "1 - Adicionar tarefa" << endl << 
        "2 - Concluir tarefa" << endl <<
        "3 - Listar tarefas pendentes" << endl <<
        "0 - Sair" << endl << 
        "Digite uma opcao: ";

        cin >> acao;
        cout << endl;
        if(acao == 1)
        {
            string nome;
            cout << "Digite o nome da tarefa: ";
            getline(cin >> ws, nome);
            gerenciadorTarefas.adicionarTarefa(nome);
        }

        else if(acao == 2)
        {
            string codigo;
            cout << "Digite o codigo da tarefa: ";
            cin >> codigo;
            gerenciadorTarefas.concluirTarefa(codigo);
        }

        else if(acao == 3)
        {
            cout << "Tarefas pendentes: " << endl;
            gerenciadorTarefas.listarPendentes();
        }

        else{check = 0;}
    }
    
    cout << "Operacao finalizada, salvando dados..." << endl;
    BancoDeDados::salvarTarefas(nomeArquivo, gerenciadorTarefas);
}