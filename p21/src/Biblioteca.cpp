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

