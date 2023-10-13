#include <stdlib.h>
#include <time.h>

#include "Turismo.hpp"

Pacote::Pacote(string nome){
    this->nome = nome;
    this->cod = geraCod(5);
}

string Pacote::getCod(){
    return this->cod;
}

string Pacote::getNome(){
    return this->nome;
}

vector<Evento*> Pacote::getEventos(){
    return this->eventos;
}

void Pacote::setCod(string cod){
    this->cod = cod;
}

void Pacote::setNome(string nome){
    this->nome = nome;
}

void Pacote::setEventos(vector<Evento*> eventos){
    this->eventos = eventos;
}

bool Pacote::addEvento(Evento* evento){
    this->eventos.push_back(evento);
    return true;
}

bool Pacote::removeEvento(Evento* evento){
    for(int i = 0; i < this->eventos.size(); i++){
        if(this->eventos[i] == evento){
            this->eventos.erase(this->eventos.begin() + i);
            return true;
        }
    }
    return false;
}

string Pacote::geraCod(int tam){
    srand (time(NULL));

    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cod = "";
    for(int i = 0; i < tam; i++){
        cod += alfabeto[rand() % alfabeto.length()];
    }
    return cod;
}
