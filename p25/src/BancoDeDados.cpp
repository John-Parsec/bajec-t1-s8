#include "Twitter.hpp"
#include <fstream>

/*
USUARIO:
nomeUsuario (unico)
nome
seguidores
seguindo

TWEET:
autor
conteudo
dataDeCriacao
*/

static void salvarDados(string nomeArquivo, RedeSocial redeSocial)
{
    
}
static void recuperarDados(string nomeArquivo, RedeSocial *redeSocial);

/*#include "Tarefas.hpp"
#include <fstream>

void BancoDeDados::salvarTarefas(string nomeArquivo, GerenciadorTarefas gerenciador)
{
    vector<Tarefa*> tarefas = gerenciador.getTarefas();
    ofstream arquivo(nomeArquivo, ios::trunc);
    
    for(int i = 0; i < tarefas.size(); i++)
    {
        arquivo << tarefas[i]->getNome() << endl;
        arquivo << tarefas[i]->getCodigo() << endl;
        arquivo << tarefas[i]->getConcluido() << endl;
    }
    arquivo.close();
}

void BancoDeDados::carregarTarefas(string nomeArquivo, GerenciadorTarefas *gerenciador)
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

        //gerenciador->adicionarTarefa(nome, codigo, concluido);
        gerenciador->adicionarTarefa(nome, codigo, concluido);
    }

    arquivo.close();
}*/