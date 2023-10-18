#include <stdlib.h>
#include <time.h>

#include "Turismo.hpp"

Venda::Venda(Cliente* cliente, Pacote* pacote){
    this->cliente = cliente;
    this->pacote = pacote;
    this->cod = geraCod(5);
}

string Venda::getCod(){
    return this->cod;
}

Cliente* Venda::getCliente(){
    return this->cliente;
}

Pacote* Venda::getPacote(){
    return this->pacote;
}

void Venda::setCod(string cod){
    this->cod = cod;
}

void Venda::setCliente(Cliente* cliente){
    this->cliente = cliente;
}

void Venda::setPacote(Pacote* pacote){
    this->pacote = pacote;
}

string Venda::geraCod(int tam){
    srand (time(NULL));

    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cod = "";
    for(int i = 0; i < tam; i++){
        cod += alfabeto[rand() % alfabeto.length()];
    }
    return cod;
}