#include "Turismo.hpp"

Roteiro::Roteiro(string nome = ""): Evento(NULL){
    this->nome = nome;
}

string Roteiro::getCod()
{
    return this->cod;
}

string Roteiro::getNome()
{
    return this->nome;
}

void Roteiro::setCod(string cod)
{
    this->cod = cod;
}

void Roteiro::setNome(string nome)
{
    this->nome = nome;
}
