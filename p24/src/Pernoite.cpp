#include "Turismo.hpp"

Pernoite::Pernoite(string local): Evento(0){
    this->local = local;
}

string Pernoite::getLocal(){
    return this->local;
}

void Pernoite::setLocal(string local){
    this->local = local;
}

string Pernoite::getTipo() const{
    return "Pernoite";
}