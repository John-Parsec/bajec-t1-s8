#include "Turismo.hpp"

Deslocamento::Deslocamento(Evento* origem, Evento* destino): Evento(0){
    this->origem = origem;
    this->destino = destino;
}

Evento* Deslocamento::getOrigem(){
    return this->origem;
}

Evento* Deslocamento::getDestino(){
    return this->destino;
}

void Deslocamento::setOrigem(Evento* origem){
    this->origem = origem;
}

void Deslocamento::setDestino(Evento* destino){
    this->destino = destino;
}