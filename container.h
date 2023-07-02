#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "Entidades.h"

#include <map>

using namespace std;

class ContainerDesenvolvedor{
    private:
        map<string, Desenvolvedor> container;
        static ContainerDesenvolvedor *instancia;
        ContainerDesenvolvedor(){};
    public:
        static  ContainerDesenvolvedor* getInstancia();
        bool incluir(Desenvolvedor);
        bool remover(Matricula);
        bool pesquisar(Desenvolvedor*);
        bool atualizar(Desenvolvedor);
        bool autenticar(Desenvolvedor);
};

class ContainerTeste{
    private:
        map<string, Teste> container;
        static ContainerTeste *instancia;
        ContainerTeste(){};
    public:
        static  ContainerTeste* getInstancia();
        bool incluir(Teste);
        bool remover(Codigo);
        bool pesquisar(Teste*);
        bool atualizar(Teste);
        bool removerPorDesenvolvedor(Matricula);
};

class ContainerCasoTeste{
    private:
        map<string, CasoTeste> container;
        static ContainerCasoTeste *instancia;
        ContainerCasoTeste(){};
    public:
        static  ContainerCasoTeste* getInstancia();
        bool incluir(CasoTeste);
        bool remover(Codigo);
        bool pesquisar(CasoTeste*);
        bool atualizar(CasoTeste);
        bool removerPorTeste(Codigo);
        bool removerPorDesenvolvedor(Matricula);
};

#endif // CONTROLADORAS_H_INCLUDED

