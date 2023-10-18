#include <stdlib.h>
#include <time.h>

#include "Turismo.hpp"

Evento::Evento(int duraçãoPrevista){
    this->duraçãoPrevista = duraçãoPrevista;
    this->cod = geraCod(5);
}

int Evento::getDuraçãoPrevista(){
    return this->duraçãoPrevista;
}

string Evento::getCod(){
    return this->cod;
}

void Evento::setDuraçãoPrevista(int duraçãoPrevista){
    this->duraçãoPrevista = duraçãoPrevista;
}

void Evento::setCod(string cod){
    this->cod = cod;
}

string Evento::geraCod(int tam){
    srand (time(NULL));

    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cod = "";
    for(int i = 0; i < tam; i++){
        cod += alfabeto[rand() % alfabeto.length()];
    }
    return cod;
}