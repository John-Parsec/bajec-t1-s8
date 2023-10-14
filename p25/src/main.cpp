#include "Twitter.hpp"
#include <iostream>

int main()
{
    RedeSocial redeSocial;
    string bdTW = "bdTweets.txt";
    string bdUS = "bdUsers.txt";

    
    BancoDeDados::recuperarDados(bdTW, bdUS, &redeSocial);
    cout << "Programa iniciado." << endl;
    redeSocial.registarUsuario("Username", "Nome com espaco");
    redeSocial.registarUsuario("Msoares", "Maria Soares");
    redeSocial.registarUsuario("Just An User", "Bartolomeu");
    
    redeSocial.buscarUsuario("Msoares");
    redeSocial.buscarUsuario("Maria Soares");

    
    Usuario *usuarioP1 = redeSocial.buscarUsuario("Msoares");
    Tweet tweet1 (usuarioP1, "Meu primeiro tweet aqui");
    Tweet tweet2 (usuarioP1, "Meu SEGUNDO tweet aqui");
    

    Usuario *usuarioP2 = redeSocial.buscarUsuario("Just An User");
    Tweet tweet3 (usuarioP2, "Meu primeiro tweet aqui P2 ");
    Tweet tweet4 (usuarioP2, "Segundo tweet aqui P2 ");
    

    Usuario *usuarioP3 = redeSocial.buscarUsuario("Username");
    Tweet tweet5 (usuarioP3, "Meu primeiro tweet aqui P3 ");
    
    
    redeSocial.adicionarTweet(&tweet1);
    redeSocial.adicionarTweet(&tweet2);
    redeSocial.adicionarTweet(&tweet3);
    redeSocial.adicionarTweet(&tweet4);
    redeSocial.adicionarTweet(&tweet5);

    
    usuarioP1->seguir(redeSocial.buscarUsuario("Just An User"));
    usuarioP1->seguir(redeSocial.buscarUsuario("Username"));

    usuarioP2->seguir(redeSocial.buscarUsuario("Msoares"));

    usuarioP3->seguir(redeSocial.buscarUsuario("Msoares"));
    usuarioP3->seguir(redeSocial.buscarUsuario("Just An User"));


    cout << "\nLista de usuarios: \n";
    for(Usuario* u : redeSocial.listarUsuarios()){
        cout << u->toStringCompleto() << endl;
    }

    cout << "\nLista de Tweets: \n";
    for(Tweet* t : redeSocial.listarTweets()){
        cout << t->toString() << endl;
    }

    vector<Tweet*> feed;
    cout << "\n\nFeed de " << usuarioP1->toStringCompleto() << endl;
    feed = usuarioP1->receberFeed(&redeSocial);
    for (Tweet* t : feed){
        cout << t->toString() << endl;
    }

    cout << "\n\nFeed de " << usuarioP2->toStringCompleto() << endl;
    feed = usuarioP2->receberFeed(&redeSocial);
    for (Tweet* t : feed){
        cout << t->toString() << endl;
    }

    cout << "\n\nFeed de " << usuarioP3->toStringCompleto() << endl;
    feed = usuarioP3->receberFeed(&redeSocial);
    for (Tweet* t : feed){
        cout << t->toString() << endl;
    }



    cout << "\nSaindo do programa. Salvando dados..." << endl;
    BancoDeDados::salvarDados(bdTW, bdUS, redeSocial);
}