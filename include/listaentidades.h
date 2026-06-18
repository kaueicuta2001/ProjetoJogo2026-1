#pragma once

#include "lista.h"
#include "entidade.h"

class ListaEntidades
{
private:
    Lista<Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();
    void Incluir(Entidade* entidade);
    void Remover(Entidade* entidade);
    void Limpar();
    int getQuantidade() const;
    Lista<Entidade>::Elemento* getPrimeiro();
    void Percorrer();
};
