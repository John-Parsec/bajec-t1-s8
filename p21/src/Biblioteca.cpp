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
        Emprestimo *emprestimo = new Emprestimo(&livro, &usuario, tempo);
        this->emprestimos.push_back(emprestimo);
        cout << "Emprestimo registrado com sucesso!" << endl;
    }
    else
    {
        cout << "Livro não disponível!" << endl;
    }
}

void Biblioteca::adicionarLivro(Livro livro, int qtde)
{
    EstoqueLivro *estoqueLivro = this->buscarEstoque(livro);
    if (estoqueLivro != NULL)
    {
        cout << "Livro ja registrada, Deseja atualizar quantidade?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Nao" << endl;
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
