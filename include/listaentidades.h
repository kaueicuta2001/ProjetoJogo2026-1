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
        void Esvaziar();
        int getQuantidade() const;
        void Percorrer();
};