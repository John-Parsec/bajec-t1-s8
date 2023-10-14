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

    redeSocial.adicionarTweet(&tweet1);
    redeSocial.adicionarTweet(&tweet2);
    
    usuarioP1->seguir(redeSocial.buscarUsuario("Just An User"));
    cout << "Quantidade de seguidores: " << usuarioP1->qntdSeguidores() << endl;
    cout << "Quantidade seguindo: " << usuarioP1->qntdSeguindo() << endl;

    cout << "Saindo do programa. Salvando dados..." << endl;
    BancoDeDados::salvarDados(bdTW, bdUS, redeSocial);
}