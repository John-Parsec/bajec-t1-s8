#include "Biblioteca.hpp"

string formatarData(time_t data)
{
    struct tm dataFormatada = *localtime(&data);
    string formatada = to_string(dataFormatada.tm_mday) + "/" + to_string(dataFormatada.tm_mon + 1) + "/" + to_string(dataFormatada.tm_year + 1900);
    return formatada;
}