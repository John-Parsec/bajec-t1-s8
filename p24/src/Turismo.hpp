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

class Dependente{
    private:
        string nome;
        Cliente* dependente_de;
    
    public:
        Dependente(string nome, Cliente* dependente_de);
        string getNome();
        Cliente* getDependenteDe();
        void setNome(string nome);
        void setDependenteDe(Cliente* dependente_de);
};

class Evento{
    private:

    protected:
        int duraçãoPrevista;
        string cod;
    
    public:
        Evento(int duraçãoPrevista);
        int getDuraçãoPrevista();
        string getCod();
        void setDuraçãoPrevista(int duraçãoPrevista);
        void setCod(string cod);
        string geraCod(int tam);
        virtual string getTipo() const = 0;
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
        string geraCod(int tam);
};

class Roteiro: public Evento{
    private:
        string nome;

    public:
        Roteiro(string nome);
        string getNome();
        void setNome(string nome);
        string getTipo() const;
};

class Deslocamento: public Evento{
    private:
        Evento* origem;
        Evento* destino;

    public:
        Deslocamento(Evento* origem, Evento* destino);
        Evento* getOrigem();
        Evento* getDestino();
        void setOrigem(Evento* origem);
        void setDestino(Evento* destino);
        string getTipo() const;
};

class Pernoite: public Evento{
    private:
        string local;

    public:
        Pernoite(string local);
        string getLocal();
        void setLocal(string local);
        string getTipo() const;
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
        string geraCod(int tam);
};

class Agencia{
    private:
        string nome;
        string cnpj;
        vector<Cliente*> clientes;
        vector<Pacote*> pacotes;
        vector<Evento*> eventos;
        vector<Venda*> vendas;
        vector<Dependente*> dependentes;

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
        void cadastarDeslocamento(Evento *origem, Evento *destino);
        void cadastarPernoite(string nome);
        void criarPacote(string nome, vector<Evento*> eventos);
        void addCliente(string nome, string cpf);
        void addDependente(string nome, int index);
        void addDependente(string nome, Cliente* dependente_de);
        void addVenda(Cliente* cliente, Pacote* pacote);
        void listarClientes();
        void listarPacotes();
};

#endif