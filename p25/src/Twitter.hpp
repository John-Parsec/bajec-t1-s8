#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Tweet;
using namespace std;

class DataHora{
    private:
        tm* dataHora;

    public:
        DataHora();
        DataHora(int dia, int mes, int ano, int hora, int minuto);
        tm* getDataHora();
        void setDataHora(int dia, int mes, int ano, int hora, int minuto);
        string toString();

        //Retorna a data e hora atual
        static DataHora dataHoraAtual();

        //Verificam apenas a Data
        bool dataAnterior(DataHora* dataHora);
        bool dataPosterior(DataHora* dataHora);
        bool dataIgual(DataHora* dataHora);
        
        //Verificam Data e HOra
        bool operator<(DataHora* dataHora);
        bool operator<=(DataHora* dataHora);
        bool operator>(DataHora* dataHora);
        bool operator>=(DataHora* dataHora);
        bool operator==(DataHora* dataHora);
        void operator=(DataHora* dataHora);
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
        void setNome(string nome); 
        string getNomeUsuario();
        void setNomeUsuario(string nomeUsuario);
        vector<Usuario*> getSeguidores();
        vector<Usuario*> getSeguindo();
        int qntdSeguidores();
        int qntdSeguindo();
        void postaTweet(Tweet* tweet);
        bool seguir(Usuario* usuario);
        vector<Tweet*> receberFeed();
        string toStringUser();
        string toStringCompleto();
        vector<Usuario*> getSeguidores();
        vector<Usuario*> getSeguindo();
};

class Tweet{
    private:
        Usuario* autor;
        string conteudo;
        DataHora dataCriacao;
    public:
        Tweet(Usuario* autor, string conteudo);
        Tweet(string conteudo, DataHora dataCriacao);
        Usuario* getAutor();
        void setAutor(Usuario *autor);
        string getConteudo();
        DataHora getDataCriacao();
        bool validaTweet(string conteudo); // verificar se tem ate 255 caracteres
        bool validaTweet();
        string toString();
};


class RedeSocial{
    private:
        vector<Usuario*> usuarios;
        static vector<Tweet*> tweets;
    public:
        bool registarUsuario(string nomeUsuario, string nome);
        static void adicionarTweet(Tweet* tweet); // inserir ordenado 
        Usuario* buscarUsuario(string nomeUsuario);
        Usuario* buscarUsuario(int index);
        vector<Usuario*> listarUsuarios();
        static vector<Tweet*> listarTweets();
};

class BancoDeDados{
    public:
        static void salvarDados(string nomeTw, string nomeUs, RedeSocial redeSocial);
        static void recuperarDados(string nomeTw, string nomeUs, RedeSocial *redeSocial);
};

#endif
