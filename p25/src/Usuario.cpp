#include "Twitter.hpp"

Usuario::Usuario(string nomeUsuario, string nome){
    this->nomeUsuario = nomeUsuario;
    this->nome = nome;
}

string Usuario::getNome(){
    return nome;
}

void Usuario::setNome(string nome){
    this->nome = nome;
}

string Usuario::getNomeUsuario(){
    return nomeUsuario;
}

void Usuario::setNomeUsuario(string nomeUsuario){
    this->nomeUsuario = nomeUsuario;
}

int Usuario::qntdSeguidores(){
    return seguidores.size();
}

int Usuario::qntdSeguindo(){
    return seguindo.size();
}

void Usuario::postaTweet(Tweet* tweet, RedeSocial *redeSocial){
    if(tweet->validaTweet())
        redeSocial->adicionarTweet(tweet);
}

bool Usuario::seguir(Usuario* usuario){
    if(usuario == this){
        return false;
    }else{
        for(Usuario* s : seguindo){
            if (s == usuario){
                return false;
            }
        }
        seguindo.push_back(usuario);
        usuario->seguidores.push_back(this);
        return true;
    }
}

vector<Tweet*> Usuario::receberFeed(RedeSocial *redeSocial){
    vector<Tweet*> tweets = redeSocial->listarTweets();
    vector<Tweet*> feed;
    for (Tweet* t : tweets){
        for(Usuario* s : seguindo){
            if (t->getAutor() == s){
                feed.push_back(t);
                break;
            }
        }
    }
    return feed;
}

string Usuario::toStringUser(){
    return nome + " (@" + nomeUsuario + ")";
}

string Usuario::toStringCompleto(){
    return toStringUser() + " | Seguidores: " + to_string(qntdSeguidores()) + " | Seguindo: " + to_string(qntdSeguindo());
}

vector<Usuario*> Usuario::getSeguindo(){
    return this-> seguindo;
}

vector<Usuario*> Usuario::getSeguidores(){
    return this-> seguidores;
}