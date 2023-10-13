# include "Tarefas.hpp"

Tarefa::Tarefa(string nome, vector<Tarefa*> tarefas)
{
    this->nome = nome;
    this->codigo = geraCodigo(tarefas);
}

Tarefa::Tarefa(string nome, string codigo, bool concluido){
    this->nome = nome;
    this->codigo = codigo;
    this->concluido = concluido;
}

string Tarefa::geraCodigo(vector<Tarefa*> tarefas)
{
    int cInt;
    string cStr;
    bool check = 0;

    while(!check)
    {
        check = 1;

        for(int i = 0; i < 7; i++)
        {
            cInt = rand() % 10;
            cStr += to_string(cInt);
        }

        for(int i = 0; i < tarefas.size(); i++)
        {
            if(cStr == tarefas[i]->getCodigo())
            {
                check = 0;
                break;
            }
        }
    }

    return cStr;
}

string Tarefa::getCodigo()
{
    return this->codigo;
}

string Tarefa::getNome()
{
    return this->nome;
}

void Tarefa::setNome(string nome)
{
    this->nome = nome;
}

bool Tarefa::getConcluido()
{
    return this-> concluido;
}

void Tarefa::setConcluido(bool concluido)
{
    this->concluido = concluido;
}

string Tarefa::toString()
{
    return (this->codigo + " - " + this->nome); 
}

