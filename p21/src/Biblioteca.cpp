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

