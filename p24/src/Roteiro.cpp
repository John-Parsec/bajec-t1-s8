#include "Turismo.hpp"

Roteiro::Roteiro(string nome): Evento(0){
    this->nome = nome;
}

string Roteiro::getNome(){
    return this->nome;
}

void Roteiro::setNome(string nome){
    this->nome = nome;
}

string Roteiro::getTipo() const{
    return "Roteiro";
}