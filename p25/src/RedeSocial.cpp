#include "Twitter.hpp"

vector<Tweet*> RedeSocial::tweets;

bool RedeSocial::registarUsuario(string nomeUsuario, string nome){
    Usuario* usuario = new Usuario(nomeUsuario, nome);
    usuarios.push_back(usuario);
    return true;
}

void RedeSocial::adicionarTweet(Tweet* tweet){
    tweets.push_back(tweet);
}

Usuario* RedeSocial::buscarUsuario(string nomeUsuario){
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i]->getNomeUsuario() == nomeUsuario){
            return usuarios[i];
        }
    }
    return NULL;
}

Usuario* RedeSocial::buscarUsuario(int index){
    return usuarios[index];
}

vector<Usuario*> RedeSocial::listarUsuarios(){
    return usuarios;
}

vector<Tweet*> RedeSocial::listarTweets(){
    return tweets;
}

