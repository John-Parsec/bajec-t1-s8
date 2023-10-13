#include "Turismo.hpp"

Evento::Evento(int duraçãoPrevista = 0){
    this->duraçãoPrevista = duraçãoPrevista;
}

int Evento::getDuraçãoPrevista(){
    return this->duraçãoPrevista;
}

void Evento::setDuraçãoPrevista(int duraçãoPrevista){
    this->duraçãoPrevista = duraçãoPrevista;
}