#pragma once

#include "lista.h"
#include "entidade.h"

namespace TheFrog{
    namespace Listas{
        class ListaEntidades
        {
            private:
            Lista<Entidades::Entidade> LEs;
            
            public:
            ListaEntidades();
            ~ListaEntidades();
            void Incluir(Entidades::Entidade* entidade);
            void Remover(Entidades::Entidade* entidade);
            void Limpar();
            int getQuantidade() const;
            Lista<Entidades::Entidade>::Elemento* getPrimeiro();
            void Percorrer();
        };
    }
}
