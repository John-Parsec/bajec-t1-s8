#include "Turismo.hpp"

Pernoite::Pernoite(string nome = ""): Evento(NULL){
    this->nome = nome;
}

string Pernoite::getCod()
{
    return this->cod;
}

string Pernoite::getNome()
{
    return this->nome;
}

void Pernoite::setCod(string cod)
{
    this->cod = cod;
}

void Pernoite::setNome(string nome)
{
    this->nome = nome;
}
