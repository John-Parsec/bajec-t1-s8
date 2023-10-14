#include "Turismo.hpp"

int main(void){
    Agencia agencia("Agencia de Turismo", "12345678910");

    Cliente* cliente1 = new Cliente("João", "12345678910");
    Cliente* cliente2 = new Cliente("Maria", "10987654321");

    agencia.addCliente(cliente1);
    agencia.addCliente(cliente2);
    agencia.addDependente("Pedro", cliente1);

    Pacote pacote1("Pacote 1");

    Roteiro* roteiro1 = new Roteiro("Roteiro 1", 5);
    Roteiro* roteiro2 = new Roteiro("Roteiro 2", 3);
    Deslocamento* deslocamento1 = new Deslocamento(roteiro1, roteiro2, 2);
    Pernoite* pernoite1 = new Pernoite("Pernoite 1", 10);
    Deslocamento* deslocamento2 = new Deslocamento(roteiro2, pernoite1, 5);

    pacote1.addEvento(roteiro1);
    pacote1.addEvento(roteiro2);
    pacote1.addEvento(deslocamento1);
    pacote1.addEvento(deslocamento2);
    pacote1.addEvento(pernoite1);

    agencia.addPacote(&pacote1);

    Venda venda1(cliente1, &pacote1);
    Venda venda2(cliente2, &pacote1);

    agencia.addVenda(&venda1);
    agencia.addVenda(&venda2);

    cout << "Agencia: " << agencia.getNome() << endl;
    cout << "CNPJ: " << agencia.getCnpj() << endl;

    cout << "Clientes:" << endl;
    agencia.listarClientes();

    cout << "Pacotes:" << endl;
    agencia.listarPacotes();

    return 0;
}