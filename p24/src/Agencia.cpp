#include "Turismo.hpp"

Agencia::Agencia(string nome = "", string cnpj = ""){
    this->nome = nome;
}

string Agencia::getNome(){
    return this->nome;
}

string Agencia::getCnpj(){
    return this->cnpj;
}

void Agencia::setNome(string nome){
    this->nome = nome;
}

void Agencia::setCnpj(string cnpj){
    this->cnpj = cnpj;
}

vector<Cliente*> Agencia::getClientes(){
    return this->clientes;
}

vector<Pacote*> Agencia::getPacotes(){
    return this->pacotes;
}

vector<Evento*> Agencia::getEventos(){
    return this->eventos;
}

vector<Venda*> Agencia::getVendas(){
    return this->vendas;
}

void Agencia::addCliente(Cliente* cliente){
    this->clientes.push_back(cliente);
}

void Agencia::addPacote(Pacote* pacote){
    this->pacotes.push_back(pacote);
}

void Agencia::addEvento(Evento* evento){
    this->eventos.push_back(evento);
}

void Agencia::addVenda(Venda* venda){
    this->vendas.push_back(venda);
}

bool Agencia::removeCliente(Cliente* cliente){
    for(auto it = this->clientes.begin(); it != this->clientes.end(); ++it){
        if(*it == cliente){
            this->clientes.erase(it);
            return true;
        }
    }
    return false;
}

bool Agencia::removePacote(Pacote* pacote){
    for(auto it = this->pacotes.begin(); it != this->pacotes.end(); ++it){
        if(*it == pacote){
            this->pacotes.erase(it);
            return true;
        }
    }
}

bool Agencia::removeEvento(Evento* evento){
    for(auto it = this->eventos.begin(); it != this->eventos.end(); ++it){
        if(*it == evento){
            this->eventos.erase(it);
            return true;
        }
    }
}

bool Agencia::removeVenda(Venda* venda){
    for(auto it = this->vendas.begin(); it != this->vendas.end(); ++it){
        if(*it == venda){
            this->vendas.erase(it);
            return true;
        }
    }
    return false;
}

void Agencia::cadastarRoteiro(string nome, int duracao){
    this->eventos.push_back(new Roteiro(nome, duracao));
}

void Agencia::cadastarDeslocamento(Evento *origem, Evento *destino, int duracao){
    this->eventos.push_back(new Deslocamento(origem, destino, duracao));
}

void Agencia::cadastarPernoite(string nome, int duracao){
    this->eventos.push_back(new Pernoite(nome, duracao));
}

void Agencia::criarPacote(string nome, vector<Evento*> eventos){
    Pacote pacote(nome);

    for(auto it = eventos.begin(); it != eventos.end(); ++it){
        pacote.addEvento(*it);
    }    

    this->pacotes.push_back(&pacote);
}

void Agencia::addCliente(string nome, string cpf){
    this->clientes.push_back(new Cliente(nome, cpf));
}

void Agencia::addDependente(string nome, Cliente* dependente_de){
    Dependente dependente(nome, dependente_de);

    this->dependentes.push_back(&dependente);
}

void Agencia::addDependente(string nome, int index){
    Dependente dependente(nome, this->clientes[index]);

    this->dependentes.push_back(&dependente);
}

void Agencia::addVenda(Cliente* cliente, Pacote* pacote){
    this->vendas.push_back(new Venda(cliente, pacote));
}

void Agencia::listarClientes(){
    for(auto it = this->clientes.begin(); it != this->clientes.end(); ++it){
        cout << (*it)->getNome() << endl;
        
        vector<Dependente *> dep;

        for(auto depedente: this->dependentes){
            if(depedente->getDependenteDe() == *it){
                dep.push_back(depedente);
            }
        }
        if(dep.size() == 0){
            cout << "\tDependentes:" << endl;
            
            for(auto depedente: dep){
                cout << "\t\t" << depedente->getNome() << endl;
            }
        }

        cout << endl;
    }
}

void Agencia::listarPacotes(){
    for(auto it = this->pacotes.begin(); it != this->pacotes.end(); ++it){
        cout << "Pacote: " << (*it)->getNome() << endl;
        cout << "\tEventos:" << endl;

        vector<Evento *> eventos = (*it)->getEventos();
        for(auto it2 = eventos.begin(); it2 != eventos.end(); ++it2){
            cout << "\t\t" << (*it2)->getTipo()  << "\t-\t" << (*it2)->getDuraçãoPrevista() << endl;
        }

        cout << endl;

        delete &eventos;
    }
}
