#ifndef TURISMO_HPP
#define TURISMO_HPP

#include <bits/stdc++.h>

using namespace std;

class Cliente{
    private:
        string nome;
        string cpf;

    public:
        Cliente(string nome, string cpf);
        string getNome();
        string getCpf();
        void setNome(string nome);
        void setCpf(string cpf);
};

class Dependete{
    private:
        string nome;
        Cliente* dependente_de;
    
    public:
        Dependete(string nome, Cliente* dependente_de);
        string getNome();
        Cliente* getDependente_de();
        void setNome(string nome);
        void setDependente_de(Cliente* dependente_de);
};

class Evento{
    private:

    protected:
        int duraçãoPrevista;
    
    public:
        Evento(int duraçãoPrevista);
        int getDuraçãoPrevista();
        void setDuraçãoPrevista(int duraçãoPrevista);
};

class Pacote{
    private:
        string cod;
        string nome;
        vector<Evento*> eventos;

    public:
        Pacote(string nome);
        string getCod();
        string getNome();
        vector<Evento*> getEventos();
        void setCod(string cod);
        void setNome(string nome);
        void setEventos(vector<Evento*> eventos);
        bool addEvento(Evento* evento);
        bool removeEvento(Evento* evento);
};

class Roteiro: public Evento{
    private:
        string cod;
        string nome;

    public:
        Roteiro(string nome);
        string getCod();
        string getNome();
        void setCod(string cod);
        void setNome(string nome);
};

class Deslocamento: public Evento{
    private:
        string cod;
        Evento* origem;
        Evento* destino;

    public:
        Deslocamento(Evento* origem, Evento* destino);
        string getCod();
        Evento* getOrigem();
        Evento* getDestino();
        void setCod(string cod);
        void setOrigem(Evento* origem);
        void setDestino(Evento* destino);
};

class Pernoite: public Evento{
    private:
        string cod;
        string nome;

    public:
        Pernoite(string nome);
        string getCod();
        string getNome();
        void setCod(string cod);
        void setNome(string nome);
};

class Venda{
    private:
        string cod;
        Cliente* cliente;
        Pacote* pacote;

    public:
        Venda(Cliente* cliente, Pacote* pacote);
        string getCod();
        Cliente* getCliente();
        Pacote* getPacote();
        void setCod(string cod);
        void setCliente(Cliente* cliente);
        void setPacote(Pacote* pacote);
};

class Agencia{
    private:
        string nome;
        string cnpj;
        vector<Cliente*> clientes;
        vector<Pacote*> pacotes;
        vector<Evento*> eventos;
        vector<Venda*> vendas;
        vector<Dependete*> dependentes;

    public:
        Agencia(string nome, string cnpj);
        string getNome();
        string getCnpj();
        vector<Cliente*> getClientes();
        vector<Pacote*> getPacotes();
        vector<Evento*> getEventos();
        vector<Venda*> getVendas();
        void setNome(string nome);
        void setCnpj(string cnpj);
        void addCliente(Cliente* cliente);
        void addPacote(Pacote* pacote);
        void addEvento(Evento* evento);
        void addVenda(Venda* venda);
        bool removeCliente(Cliente* cliente);
        bool removePacote(Pacote* pacote);
        bool removeEvento(Evento* evento);
        bool removeVenda(Venda* venda);
        void cadastarRoteiro(string nome);
        void cadastarDeslocamento(Evento origem, Evento destino);
        void cadastarPernoite(string nome);
        void criarPacote(string nome, vector<Evento*> eventos);
        void addCliente(string nome, string cpf);
        void addDependente(string nome, int index);
        void addDependente(string nome, Cliente* dependente_de);
        void addVenda(Cliente* cliente, Pacote* pacote);
};

#endif