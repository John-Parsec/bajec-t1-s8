#include "Turismo.hpp"

Deslocamento:: Deslocamento(Evento* origem , Evento* destino): Evento(NULL){
    this->origem = origem;
    this->destino = destino;
}

string Deslocamento::getCod()
{
    return this->cod;
}

Evento* Deslocamento::getOrigem()
{
    return this->origem;
}

Evento* Deslocamento::getDestino()
{
    return this->destino;
}

void Deslocamento::setCod(string cod)
{
    this->cod = cod;
}

void Deslocamento::setOrigem(Evento* origem)
{
    this->origem = origem;
}

void Deslocamento::setDestino(Evento* destino)
{
    this->destino = destino;
}

