#include "Twitter.hpp"
#include <iostream>

int main()
{
    RedeSocial redeSocial;
    string bdTW = "bdTweets.txt";
    string bdUS = "bdUsers.txt";

    BancoDeDados::recuperarDados(bdTW, bdUS, &redeSocial);
    cout << "Saindo do programa. Salvando dados..." << endl;
    BancoDeDados::salvarDados(bdTW, bdUS, redeSocial);
}