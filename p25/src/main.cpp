#include "Twitter.hpp"
#include <iostream>

int main()
{
    RedeSocial redeSocial;
    string bdTW = "bdTweets.txt";
    string bdUS = "bdUsers.txt";

    BancoDeDados::recuperarDados(bdTW, bdUS, &redeSocial);

    BancoDeDados::salvarDados(bdTW, bdUS, redeSocial);
}