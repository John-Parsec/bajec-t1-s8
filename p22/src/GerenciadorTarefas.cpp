# include "Tarefas.hpp"

void GerenciadorTarefas::adicionarTarefa(string nome){
    Tarefa* tarefa = new Tarefa(nome, tarefas);
    tarefas.push_back(tarefa);
}

void GerenciadorTarefas::adicionarTarefa(string nome, string codigo, bool concluido){
    Tarefa* tarefa = new Tarefa(nome, codigo, concluido);
    tarefas.push_back(tarefa);
}

void GerenciadorTarefas::concluirTarefa(string codigo){
    Tarefa* tarefa = getTarefa(codigo);
    tarefa->setConcluido(true);
}

void GerenciadorTarefas::listarPendentes(){
    int i;

    for (i = 0; i < tarefas.size(); i++){
        if (!tarefas[i]->getConcluido()){
            cout << tarefas[i]->toString() << endl;
        }
    }
}

int GerenciadorTarefas::getQuantidadeDeTarefas(){
    return tarefas.size();
}

Tarefa* GerenciadorTarefas::getTarefa(string codigo){
    int i;

    for (i = 0; i < tarefas.size(); i++){
        if (tarefas[i]->getCodigo() == codigo){
            return tarefas[i];
        }
    }

    cout << "Tarefa nao encontrada";
}

Tarefa* GerenciadorTarefas::getTarefa(int index){
    return tarefas[index];
}

vector<Tarefa*> GerenciadorTarefas::getTarefas(){
    return tarefas;
}