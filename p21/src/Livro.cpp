#include "Biblioteca.hpp"

Livro::Livro(string autor = "", string titulo = ""){
    this->autor = autor;
    this->titulo = titulo;
}

void Livro::setAutor(string autor){
    this->autor = autor;
}

void Livro::setTitulo(string titulo){
    this->titulo = titulo;
}

string Livro::getAutor(){
    return this->autor;
}

string Livro::getTitulo(){
    return this->titulo;
}