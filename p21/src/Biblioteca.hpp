#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Usuario{
    private:
        string nome;
        string cpf;
        string telefone;

    public:
        Usuario(string nome, string cpf, string telefone);
        string getNome();
        string getTelefone();
        string getCPF();

        void setNome(string nome);
        void setCPF(string cpf);
        void setTelefone(string telefone);
};

class Livro{
    private:
        string autor;
        string titulo;

    public:
        Livro(string autor, string titulo);
        string getAutor();
        string getTitulo();

        void setAutor(string autor);
        void setTitulo(string titulo);

};

struct EstoqueLivro{
    Livro* livro;
    int qtde;
};

class Data{

};

/*class Emprestimo{
    private:
        Livro* livro;
        Usuario* usuario;
        Data dataInicio;
        Data dataDevolucao;
        bool devolvido;
    public:
        Emprestimo(Livro* livro, Usuario* usuario, Data dataInicio);
        Livro* getLivro();
        Usuario* getUsuario();
        void setDataDevolucao(Data dataDevolucao);
        
};*/
class Emprestimo{
    private:
        Livro* livro;
        Usuario* usuario;
        time_t dataInicio;
        bool devolvido;
    public:
        Emprestimo(Livro* livro, Usuario* usuario, time_t dataInicio);
        Livro getLivro();
        Usuario getUsuario();
        void setDataDevolucao(Data dataDevolucao);
        
};

string formatarData(time_t data);

class Biblioteca{
    private:
        vector<EstoqueLivro*> estoque;
        vector<Emprestimo*> emprestimos;
        vector<Usuario*> usuarios;
    public:
        void adicionarLivro(Livro livro, int qtde);
        void registrarEmprestimo(Livro livro, Usuario usuario);
        bool livroDisponivel(Livro livro);
        EstoqueLivro* buscarEstoque(Livro livro);
        void devolverLivro(Livro livro, Usuario usuario);
};

#endif