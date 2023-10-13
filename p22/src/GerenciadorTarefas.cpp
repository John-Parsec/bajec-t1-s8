# include "Tarefas.hpp"

void GerenciadorTarefas::adicionarTarefa(string nome){
    Tarefa* tarefa = new Tarefa(nome);
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
}

Tarefa* GerenciadorTarefas::getTarefa(int index){
    return tarefas[index];
}