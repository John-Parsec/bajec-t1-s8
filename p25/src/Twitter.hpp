#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <vector>
#include <string>

class Tweet;
using namespace std;

class DataHora{

};

class Usuario{
    private:
        string nomeUsuario;
        string nome;
        vector<Usuario*> seguidores;
        vector<Usuario*> seguindo;
    public:
        Usuario(string nomeUsuario, string nome);
        string getNome();
        string getNomeUsuario();
        void setNome(string nome);
        void setNomeUsuario(string nomeUsuario);
        void postaTweet(Tweet* tweet);
        void seguir(Usuario* usuario);
        vector<Tweet*> receberFeed();
        string toString();
};

class Tweet{
    private:
        Usuario* autor;
        string conteudo;
        DataHora dataCriacao;
    public:
        Tweet(Usuario* autor, string conteudo);
        Usuario* getAutor();
        string getConteudo();
        DataHora getDataCriacao();
        bool validaTweet(string conteudo); // verificar se tem ate 255 caracteres
        string toString();
};


class RedeSocial{
    private:
        vector<Usuario*> usuarios;
        vector<Tweet*> usuarios;
    public:
        bool registarUsuario(string nomeUsuario, string nome);
        Usuario* buscarUsuario(string nomeUsuario);
        Usuario* buscarUsuario(int index);
        vector<Usuario*> listarUsuarios();
        vector<Tweet*> listarTweets();
};

class BancoDeDados{
    public:
        void salvarDados(string nomeArquivo);
        void recuperarDados(string nomeArquivo);
};

#endif
