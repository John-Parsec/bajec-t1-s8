#include "Tarefas.hpp"
#include <fstream>

static void salvarTarefas(string nomeArquivo, GerenciadorTarefas gerenciador)
{
    vector<Tarefa*> tarefas = gerenciador.getTarefas();
    ofstream arquivo(nomeArquivo, ios::trunc);

    /*
    if(!arquivo.good())
    {
        cout << "Erro: arquivo nao encontrado." << endl;
        return;
    }
    */
    
    for(int i = 0; i < tarefas.size(); i++)
    {
        arquivo << tarefas[i]->getNome() << endl;
        arquivo << tarefas[i]->getCodigo() << endl;
        arquivo << tarefas[i]->getConcluido() << endl;
    }

    arquivo.close();
}

static void carregarTarefas(string nomeArquivo, GerenciadorTarefas *gerenciador)
{
    ifstream arquivo(nomeArquivo);

    string codigo, nome, strConcluido;
    bool concluido;

    while(arquivo)
    {
        getline(arquivo, nome);
        if(!arquivo)
            {break;}

        getline(arquivo, codigo);
        getline(arquivo, strConcluido);
        concluido = stoi(strConcluido);

        *gerenciador->adicionarTarefa(nome, codigo, concluido);
    }

    arquivo.close();
}