#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include "Biblioteca.hpp"
using namespace std;

int main(void)
{
    Livro livro1("Machado", "Dom Casmurro");
    Livro livro2("Mario", "Macunaima");
    Livro livro3("Paulo", "O Alquimista");
    Livro livro4("Clarice", "A Hora da ");

    Usuario usuario1("Leticia", "12345675890", "123456789");
    Usuario usuario2("Patricia", "0000000000", "7398181818");
    Usuario usuario3("Caio", "894561237", "00000000000");

    Biblioteca biblioteca;

    biblioteca.adicionarLivro(livro1, 10);
    biblioteca.adicionarLivro(livro2, 3);
    biblioteca.adicionarLivro(livro3, 1);
    biblioteca.adicionarLivro(livro4, 1);
    Biblioteca ::listarLivros(biblioteca.getEstoque());

    biblioteca.registrarEmprestimo(livro1, usuario1);
    biblioteca.registrarEmprestimo(livro1, usuario2);
    biblioteca.registrarEmprestimo(livro1, usuario3);
    biblioteca.registrarEmprestimo(livro2, usuario1);
    biblioteca.registrarEmprestimo(livro3, usuario1);
    biblioteca.registrarEmprestimo(livro4, usuario3);

    biblioteca.registrarEmprestimo(livro4, usuario2); // não deve ser registrado pois não há estoque

    biblioteca.devolverLivro(livro4, usuario3);
    Biblioteca ::listarLivros(biblioteca.getEstoque());

    biblioteca.registrarEmprestimo(livro4, usuario2); // agora pode ser registrado pois há estoque

    Biblioteca::listarEmprestimos(biblioteca.getEmprestimos());
    Biblioteca::listarEmprestimos(biblioteca.getEmprestimos(), usuario3); // listar empréstimos de um usuário, neste caso do usuário3

    return 0;
}