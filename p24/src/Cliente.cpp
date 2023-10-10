#include "Turismo.hpp"

Cliente::Cliente(string nome = "", string cpf = ""){
    this->nome = nome;
    this->cpf = cpf;
}

string Cliente::getNome(){
    return this->nome;
}

string Cliente::getCpf(){
    return this->cpf;
}

void Cliente::setNome(string nome){
    this->nome = nome;
}

void Cliente::setCpf(string cpf){
    this->cpf = cpf;
}