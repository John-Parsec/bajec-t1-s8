#ifndef TAREFAS_HPP
#define TAREFAS_HPP

# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Tarefa{
    private:
        string codigo;
        string nome;
        bool concluido;
    public:
        Tarefa(string nome, vector<Tarefa*> tarefas);
        Tarefa(string nome, string codigo, bool concluido);
        string geraCodigo(vector<Tarefa*> tarefas);
        string getCodigo();
        string getNome();
        void setNome(string nome);
        bool getConcluido();
        void setConcluido(bool concluido);
        string toString();
};
 

class GerenciadorTarefas{
    private:
        vector<Tarefa*> tarefas;
    public:
        void adicionarTarefa(string nome);
        void adicionarTarefa(string nome, string codigo, bool concluido);
        void concluirTarefa(string codigo);
        void listarPendentes();
        int getQuantidadeDeTarefas();
        Tarefa* getTarefa(string codigo);
        Tarefa* getTarefa(int index);
        vector<Tarefa*> getTarefas();
};

class BancoDeDados{
    public:
        static void salvarTarefas(string nomeArquivo, GerenciadorTarefas gerenciador);
        static void carregarTarefas(string nomeArquivo, GerenciadorTarefas *gerenciador);
};

#endif