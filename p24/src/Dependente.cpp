#include "Turismo.hpp"

Dependente::Dependente(string nome, Cliente* dependente_de){
    this->nome = nome;
    this->dependente_de = dependente_de;
}

string Dependente::getNome(){
    return this->nome;
}

Cliente* Dependente::getDependenteDe(){
    return this->dependente_de;
}

void Dependente::setNome(string nome){
    this->nome = nome;
}

void Dependente::setDependenteDe(Cliente* dependente_de){
    this->dependente_de = dependente_de;
}