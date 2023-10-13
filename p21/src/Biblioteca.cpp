#include "Biblioteca.hpp"

bool Biblioteca::livroDisponivel(Livro livro)
{
    EstoqueLivro *estoque = buscarEstoque(livro);
    if (estoque->qtde > 0)
        return true;
    else
        return false;
}

// testar apos implementar a adicionarLivro
EstoqueLivro *Biblioteca::buscarEstoque(Livro livro)
{
    for (int i = 0; i < estoque.size(); i++)
    {
        if (estoque[i]->livro->getTitulo() == livro.getTitulo() && estoque[i]->livro->getAutor() == livro.getAutor())
        {
            return estoque[i];
        }
    }
    return NULL;
}

void Biblioteca::registrarEmprestimo(Livro livro, Usuario usuario)
{
    if (livroDisponivel(livro))
    {
        EstoqueLivro *estoqueLivro = buscarEstoque(livro);
        estoqueLivro->qtde--;
        time_t tempo;
        tempo = time(NULL);
        struct tm data = *localtime(&tempo);
        string completa = to_string(data.tm_mday) + "/" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
       // Emprestimo *emprestimo = new Emprestimo(&livro, &usuario, completa); // falta implementar a classe Data
       // emprestimos.push_back(emprestimo);
    }
}

void Biblioteca::adicionarLivro(Livro livro, int qtde)
{
    EstoqueLivro *estoqueLivro = buscarEstoque(livro);
    if (estoqueLivro != NULL)
    {
        cout << "Livro já registrada, Deseja atualizar quantidade?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        int opcao;
        cin >> opcao;
        if (opcao == 1)
            estoqueLivro->qtde += qtde;
    }
    else
    {
        EstoqueLivro *estoqueLivro = new EstoqueLivro();
        estoqueLivro->livro = &livro;
        estoqueLivro->qtde = qtde;
        this->estoque.push_back(estoqueLivro);
        cout << "Livro adicionado com sucesso!" << endl;
    }
}



