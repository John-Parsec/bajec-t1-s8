#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include "Biblioteca.hpp"
using namespace std;

int main(void) {
    time_t tempo;
    tempo = time(NULL);
    cout <<"Data:"<< formatarData(tempo) << endl;
    /*struct tm data = *localtime(&tempo);
    string completa = to_string( data.tm_mday)+"/"+ to_string(data.tm_mon + 1) +"/"+ to_string(data.tm_year + 1900);
    cout << completa << endl;
    time_t futuro = tempo + 21 * 24 * 60 * 60;
    data = *localtime(&futuro);
    completa = to_string( data.tm_mday)+"/"+ to_string(data.tm_mon + 1) +"/"+ to_string(data.tm_year + 1900);
    cout <<"apos 7 dias:"<< completa << endl;*/
}