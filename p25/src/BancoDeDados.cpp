#include "Twitter.hpp"
#include <fstream>

void BancoDeDados::salvarDados(string nomeTw, string nomeUs, RedeSocial redeSocial)
{
    //TWEET
    vector<Tweet*> tweets = redeSocial.listarTweets();
    ofstream arquivoTw(nomeTw, ios::trunc);

    for(unsigned int i = 0; i < tweets.size(); i++)
    {
        arquivoTw << tweets[i]->getAutor()->getNomeUsuario() << endl;
        arquivoTw << tweets[i]->getDataCriacao().toString() << endl;
        arquivoTw << tweets[i]->getConteudo() << endl;
    }
    arquivoTw.close();

    //USER
    vector<Usuario*> usuarios = redeSocial.listarUsuarios();
    ofstream arquivoUs(nomeUs, ios::trunc);

    for(unsigned int i = 0; i < usuarios.size(); i++)
    {
        arquivoUs << usuarios[i]->getNomeUsuario() << endl;
        arquivoUs << usuarios[i]->getNome() << endl;

        vector<Usuario*> seguindo = usuarios[i]->getSeguindo();
        for(unsigned int j = 0; j < seguindo.size(); i++)
        {
            arquivoUs << seguindo[j]->getNomeUsuario() << endl;
        }

        cout << endl;
    }
    arquivoUs.close();
}

void BancoDeDados::recuperarDados(string nomeTw, string nomeUs, RedeSocial *redeSocial)
{
    vector<string> tweetsPointers;
    ifstream arquivoTw(nomeTw);
    string autor, conteudo, strDh;
    DataHora dataHora;

    //TWEET CRIANDO
    while(arquivoTw)
    {
        getline(arquivoTw, autor);
        if(!arquivoTw)
            {break;}
        tweetsPointers.push_back(autor);
        getline(arquivoTw, strDh);
        getline(arquivoTw, conteudo);

        int dia, mes, ano, hora, minuto;
        dia = stoi(strDh.substr(0, 2));
        mes = stoi(strDh.substr(3, 2));
        ano = stoi(strDh.substr(6, 4));
        hora = stoi(strDh.substr(11, 2));
        minuto = stoi(strDh.substr(14, 2));
        dataHora.setDataHora(dia, mes, ano, hora, minuto);

        Tweet* tweet = new Tweet(conteudo, dataHora);
        redeSocial->adicionarTweet(tweet);
    }

    arquivoTw.close();

    //USER CRIANDO
    struct structSeguindo
    {
        vector<string> seguindo;
    };
    vector<structSeguindo> segPointers;
    ifstream arquivoUs(nomeUs);
    string nomeUsuario, nome;
    while(arquivoUs)
    {
        getline(arquivoUs, nomeUsuario);
        if(!arquivoUs)
            {break;}
        getline(arquivoUs, nome);
        
        structSeguindo lista;
        string seguindo;

        getline(arquivoUs, seguindo);
        while(seguindo != " ")
        {
            lista.seguindo.push_back(seguindo);
            getline(arquivoUs, seguindo);
        }
        
        segPointers.push_back(lista);
        redeSocial->registarUsuario(nomeUsuario, nome);
    }

    arquivoUs.close();

    //TWEET POINTER
    vector<Tweet*> pointerTweets = redeSocial->listarTweets();
    for(unsigned int i = 0; i < pointerTweets.size(); i++)
    {
        Usuario *userP = redeSocial->buscarUsuario(tweetsPointers[i]);
        pointerTweets[i]->setAutor(userP);
    }

    //USER POINTER
    vector<Usuario*> pointerUsuarios = redeSocial->listarUsuarios();
    for(unsigned int i = 0; i < pointerUsuarios.size(); i++)
    {
        for(unsigned int j = 0; j < segPointers[i].seguindo.size(); j++)
        {
            Usuario *userP = redeSocial->buscarUsuario(segPointers[i].seguindo[j]);
            pointerUsuarios[i]->seguir(userP);
        }
    }
}