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
    LEs.Remover(entidade);
}

void ListaEntidades::Esvaziar()
{
    LEs.Esvaziar();
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

    while (atual != nullptr) {
        Entidade* pEntidade = atual->getInfo();
        Lista<Entidade>::Elemento* proximo = atual->getProximo();

        if (!pEntidade->getVivo()) {
            Remover(pEntidade);
        } else {
            pEntidade->Executar();
        }

        atual = proximo;
    }
}
