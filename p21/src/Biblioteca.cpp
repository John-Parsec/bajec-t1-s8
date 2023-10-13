#include "Biblioteca.hpp"

bool Biblioteca::livroDisponivel(Livro livro){
    EstoqueLivro* estoque = buscarEstoque(livro);
    if (estoque->qtde > 0)
        return true;
    else
        return false;

}

// testar apos implementar a adicionarLivro
EstoqueLivro* Biblioteca::buscarEstoque(Livro livro){
    for (int i = 0; i < estoque.size(); i++){
        if (estoque[i]->livro->getTitulo() == livro.getTitulo() && estoque[i]->livro->getAutor() == livro.getAutor()){
            return estoque[i];
        }
    }
}

void Biblioteca::registrarEmprestimo(Livro livro, Usuario usuario){
    if (livroDisponivel(livro)){
        EstoqueLivro* estoqueLivro = buscarEstoque(livro);
        estoqueLivro->qtde--;
        Emprestimo* emprestimo = new Emprestimo(&livro, &usuario, Data()); // falta implementar a classe Data
        emprestimos.push_back(emprestimo);
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

