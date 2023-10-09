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
        Tarefa(string nome);
        string geraCodigo();
        int getCodigo();
        string getNome();
        void setNome(string nome);
        bool getConcluido();
        void setConcluido(bool concluido);
};
 

class GerenciadorTarefas{
    private:
        vector<Tarefa*> tarefas
    public:
        void adicionarTarefa(string nome);
        void concluirTarefa();
        void listarPendentes();
        int getQuantidadeDeTarefas();
        int getTarefa(string codigo);
        int getTarefa(int index);
};

class BancoDeDados{
    public:
        static void salvarTarefas(string nomeArquivo);
        static void carregarTarefas(string nomeArquivo);
};

#endif