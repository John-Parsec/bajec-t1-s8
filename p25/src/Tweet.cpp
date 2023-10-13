#include "Twitter.hpp"

Tweet::Tweet(Usuario* autor, string conteudo){
    this->autor = autor;
    this->conteudo = conteudo;
    this->dataCriacao = DataHora::dataHoraAtual();
}

Usuario* Tweet::getAutor(){
    return this->autor;
}

string Tweet::getConteudo(){
    return this->conteudo;
}

DataHora Tweet::getDataCriacao(){
    return this->dataCriacao; 
}

// verificar se tem ate 255 caracteres
bool Tweet::validaTweet(string conteudo){
    if(conteudo.length() > 255){
        return false;
    }else{
        return true;
    }
}

string Tweet::toString(){
    return "@"+ this->autor->getNomeUsuario() + "( " + this->dataCriacao.toString() +" ): " + this->conteudo;
}