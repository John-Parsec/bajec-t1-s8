#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include "Biblioteca.hpp"
using namespace std;

int main(void) {
    Livro livro1("Ana Lima", "Pé de figo");


    Usuario usuario1("Leticia", "123456789", "123456789");
    Usuario usuario2("Patricia", "123456789", "123456789");
    Usuario usuario3("Caio", "123456789", "123456789");

    Biblioteca biblioteca;
    biblioteca.adicionarLivro(livro1, 2);
    biblioteca.registrarEmprestimo(livro1, usuario1);
    biblioteca.registrarEmprestimo(livro1, usuario2);
    biblioteca.registrarEmprestimo(livro1, usuario3);





    /*struct tm data = *localtime(&tempo);
    string completa = to_string( data.tm_mday)+"/"+ to_string(data.tm_mon + 1) +"/"+ to_string(data.tm_year + 1900);
    cout << completa << endl;
    time_t futuro = tempo + 21 * 24 * 60 * 60;
    data = *localtime(&futuro);
    completa = to_string( data.tm_mday)+"/"+ to_string(data.tm_mon + 1) +"/"+ to_string(data.tm_year + 1900);
    cout <<"apos 7 dias:"<< completa << endl;*/
}