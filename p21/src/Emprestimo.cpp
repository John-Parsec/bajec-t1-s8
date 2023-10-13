#include "Biblioteca.hpp"

Emprestimo::Emprestimo(Livro* livro, Usuario* usuario, time_t dataInicio){
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

time_t Emprestimo::getDataInicio(){
    return this->dataInicio;
}

bool Emprestimo::getDevolvido(){
    return this->devolvido;
}

void Emprestimo::setDevolvido(bool devolvido){
    this->devolvido = devolvido;
}



