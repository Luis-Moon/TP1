#include "Containers.h"
#include "Telas.h"

#include <list>
#include <iostream>

ContainerDesenvolvedor* ContainerDesenvolvedor::instancia = nullptr;

ContainerDesenvolvedor* ContainerDesenvolvedor::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerDesenvolvedor();
    return instancia;
}

bool ContainerDesenvolvedor::incluir(Desenvolvedor desenvolvedor){
    return container.insert(make_pair(desenvolvedor.getMatricula().getValor(), desenvolvedor)).second;
}

bool ContainerDesenvolvedor::remover(Matricula matricula){
    map<string, Desenvolvedor>::iterator it = container.find(matricula.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerDesenvolvedor::pesquisar(Desenvolvedor * desenvolvedor){
    map<string, Desenvolvedor>::iterator it = container.find(desenvolvedor->getMatricula().getValor());
    if(it != container.end()){
        *desenvolvedor = it->second;
        return true;
    }
    return false;
}

bool ContainerDesenvolvedor::autenticar(Desenvolvedor desenvolvedor) {
    map<string, Desenvolvedor>::iterator it = container.find(desenvolvedor.getMatricula().getValor());
    if(it != container.end() && it->second.getSenha().getValor() == desenvolvedor.getSenha().getValor()){
        return true;
    }
    return false;
}

bool ContainerDesenvolvedor::atualizar(Desenvolvedor desenvolvedor){
    map<string, Desenvolvedor>::iterator it = container.find(desenvolvedor.getMatricula().getValor());
    if(it != container.end()){
        it->second = desenvolvedor;
        return true;
    }
    return false;
}



ContainerTeste* ContainerTeste::instancia = nullptr;


ContainerTeste* ContainerTeste::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerTeste();
    return instancia;
}

bool ContainerTeste::incluir(Teste teste){
    return container.insert(make_pair(teste.getCodigo().getValor(), teste)).second;
}

bool ContainerTeste::remover(Codigo codigo){
    map<string, Teste>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerTeste::pesquisar(Teste* teste){
    map<string, Teste>::iterator it = container.find(teste->getCodigo().getValor());
    if(it != container.end()){
            if(it->second.getDesenvolvedor().getValor() == teste->getDesenvolvedor().getValor()){
               *teste = it->second;
               return true;
            }
    }
    return false;
}

bool ContainerTeste::atualizar(Teste teste){
    map<string, Teste>::iterator it = container.find(teste.getCodigo().getValor());
    if(it != container.end()){
        if(it->second.getDesenvolvedor().getValor() == teste.getDesenvolvedor().getValor()){
        it->second = teste;
        return true;
        }
    }
    return false;
}

bool ContainerTeste::removerPorDesenvolvedor(Matricula desenvolvedor) {
    list<Codigo> paraRemover;
    for (map<string, Teste>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->second.getDesenvolvedor().getValor() == desenvolvedor.getValor()) {
                paraRemover.push_front(it->second.getCodigo());
        }
    }

    for (list<Codigo>::iterator it = paraRemover.begin(); it != paraRemover.end(); ++it) {
        remover(*it);
    }
    return true;
}

ContainerCasoTeste* ContainerCasoTeste::instancia = nullptr;


ContainerCasoTeste* ContainerCasoTeste::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerCasoTeste();
    return instancia;
}

bool ContainerCasoTeste::incluir(CasoTeste casoteste){
    return container.insert(make_pair(casoteste.getCodigo().getValor(), casoteste)).second;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ContainerCasoTeste::remover(Codigo codigo){
    map<string, CasoTeste>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerCasoTeste::pesquisar(CasoTeste* casoteste){
    map<string, CasoTeste>::iterator it = container.find(casoteste->getCodigo().getValor());
    if(it != container.end()){
            if(it->second.getDesenvolvedor().getValor() == casoteste->getDesenvolvedor().getValor()){
               *casoteste = it->second;
               return true;
            }
    }
    return false;
}

bool ContainerCasoTeste::atualizar(CasoTeste casoteste){
    map<string, CasoTeste>::iterator it = container.find(casoteste.getCodigo().getValor());
    if(it != container.end()){
        if(it->second.getDesenvolvedor().getValor() == casoteste.getDesenvolvedor().getValor()){
        it->second = casoteste;
        return true;
        }
    }
    return false;
}
//projeto usuario tarefa
bool ContainerCasoTeste::removerPorTeste(Codigo teste) {
    list<Codigo> paraRemover;
    for (map<string, CasoTeste>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->second.getTeste().getValor() == teste.getValor()) {
                paraRemover.push_front(it->second.getCodigo());
        }
    }

    for (list<Codigo>::iterator it = paraRemover.begin(); it != paraRemover.end(); ++it) {
        remover(*it);
    }
    return true;
}

bool ContainerCasoTeste::removerPorDesenvolvedor(Matricula desenvolvedor) {
    list<Codigo> paraRemover;
    for (map<string, CasoTeste>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->second.getDesenvolvedor().getValor() == desenvolvedor.getValor()) {
                paraRemover.push_front(it->second.getCodigo());
        }
    }

    for (list<Codigo>::iterator it = paraRemover.begin(); it != paraRemover.end(); ++it) {
        remover(*it);
    }
    return true;
}

