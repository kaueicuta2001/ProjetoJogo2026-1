#include "listaentidades.h"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades()
{
    Esvaziar();
}

void ListaEntidades::Incluir(Entidade* entidade)
{
    LEs.Incluir(entidade);
}

void ListaEntidades::Remover(Entidade* entidade)
{
    LEs.remover(entidade);
}

void ListaEntidades::Esvaziar()
{
    LEs.esvaziar();
}

int ListaEntidades::getQuantidade() const
{
    return LEs.getQuantidade();
}

Lista<Entidade>::Elemento* ListaEntidades::getPrimeiro()
{
    return LEs.getPrimeiro();
}

void ListaEntidades::Percorrer()
{
    Lista<Entidade>::Elemento* atual = LEs.getPrimeiro();

    while (atual != nullptr)
    {
        Entidade* entidade = atual->getInfo();
        entidade->Executar();
        atual = atual->getProximo();
    }
}
