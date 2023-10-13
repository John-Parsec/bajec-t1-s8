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
        cout << "Livro nao disponível!" << endl;
    }
}

void Biblioteca::adicionarLivro(Livro livro, int qtde)
{
    EstoqueLivro *estoqueLivro = this->buscarEstoque(livro);
    if (estoqueLivro != NULL)
    {
        cout << "Livro ja registrado, Deseja atualizar quantidade?" << endl;
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

void Biblioteca ::devolverLivro(Livro livro, Usuario usuario)
{
    EstoqueLivro *estoque = buscarEstoque(livro);
    for (int i = 0; i < emprestimos.size(); i++)
    {
        if (emprestimos[i]->getLivro()->getTitulo() == livro.getTitulo() && emprestimos[i]->getLivro()->getAutor() == livro.getAutor() && emprestimos[i]->getDevolvido() == false && emprestimos[i]->getUsuario()->getCPF() == usuario.getCPF())

        {

            emprestimos[i]->setDevolvido(true);
            cout << "Livro devolvido com sucesso!" << endl;
            estoque->qtde++;
            return;
        }
    }
    cout << "Devolucao nao aceita" << endl;
}

void Biblioteca ::listarEmprestimos(vector<Emprestimo *> emprestimos)
{
    cout << "Emprestimos:" << endl;
    cout << left;
    cout << setw(20) << "Livro" << setw(20) << "Autor" << setw(20) << "Usuario" << setw(20) << "Dt emprestimo" << setw(20) << setw(20) << "Devolvido" << endl;
    for (int i = 0; i < emprestimos.size(); i++)
    {
        cout << setw(20);
        cout << emprestimos[i]->getLivro()->getTitulo() << setw(20);
        cout << emprestimos[i]->getLivro()->getAutor() << setw(20);
        cout << emprestimos[i]->getUsuario()->getNome() << setw(20);
        cout << formatarData(emprestimos[i]->getDataInicio()) << setw(20);
        cout << (emprestimos[i]->getDevolvido() ? "Sim" : "Nao");
        cout << endl;
    }
}

void Biblioteca::listarLivros(vector<EstoqueLivro *> estoque)
{
    cout << endl;
    cout << "Livros:" << endl;
    cout << left;
    cout << setw(20) << "Livro" << setw(20) << "Autor" << setw(20) << "Qtde" << endl;
    for (int i = 0; i < estoque.size(); i++)
    {
        cout << setw(20);
        cout << estoque[i]->livro->getTitulo() << setw(20);
        cout << estoque[i]->livro->getAutor() << setw(20);
        cout << estoque[i]->qtde << setw(20);
        cout << endl;
    }
}

void Biblioteca::listarEmprestimos(vector<Emprestimo *> emprestimos, Usuario usuario)
{
    cout << endl;
    cout << "Emprestimo(s) feito(s) por " << usuario.getNome() << ":" << endl;
    cout << left;
    cout << setw(20) << "Livro" << setw(20) << "Autor" << setw(20) << "Usuario" << setw(20) << "Dt emprestimo" << setw(20) << setw(20) << "Devolvido" << endl;
    if (emprestimos.size() == 0)
    {
        cout << "Nenhum emprestimo encontrado" << endl;
        return;
    }
    for (int i = 0; i < emprestimos.size(); i++)
    {
        if (emprestimos[i]->getUsuario()->getCPF() == usuario.getCPF())
        {
            cout << setw(20);
            cout << emprestimos[i]->getLivro()->getTitulo() << setw(20);
            cout << emprestimos[i]->getLivro()->getAutor() << setw(20);
            cout << emprestimos[i]->getUsuario()->getNome() << setw(20);
            cout << formatarData(emprestimos[i]->getDataInicio()) << setw(20);
            cout << (emprestimos[i]->getDevolvido() ? "Sim" : "Nao");

            cout << endl;
        }
    }
}

vector<EstoqueLivro *> Biblioteca ::getEstoque()
{
    return this->estoque;
}

vector<Emprestimo *> Biblioteca ::getEmprestimos()
{
    return this->emprestimos;
}
