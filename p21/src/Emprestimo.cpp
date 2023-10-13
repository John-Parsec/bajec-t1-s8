#include "Biblioteca.hpp"

Emprestimo::Emprestimo(Livro* livro, Usuario* usuario, Data dataInicio){
    this->livro = livro;
    this->usuario = usuario;
    this->dataInicio = dataInicio;
    this->devolvido = false;
};

Livro* Emprestimo::getLivro(){
    return this->livro;
}

Usuario* Emprestimo::getUsuario(){
    return this->usuario;
}

void Emprestimo::setDataDevolucao(Data dataDevolucao){
    this->dataDevolucao = dataDevolucao;
    this->devolvido = true;
}