#include "Biblioteca.hpp"

Usuario :: Usuario (string nome, string cpf, string telefone){
    this->nome = nome;
    this->cpf = cpf;
    this->telefone = telefone;
}

string Usuario :: getNome(){
    return this->nome;
}

string Usuario :: getTelefone(){
    return this->telefone;
}

string Usuario :: getCPF(){
    return this->cpf;
}

void Usuario :: setNome(string nome){
    this->nome = nome;
}

void Usuario :: setTelefone(string telefone){
    this->telefone = telefone;
}