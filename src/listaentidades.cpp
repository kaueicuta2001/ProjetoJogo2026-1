#include "listaentidades.h"

using namespace std;

ListaEntidades::ListaEntidades()
{
    
}

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

void ListaEntidades::Percorrer()
{
    Lista<Entidade>::Elemento* atual = LEs.getPrimeiro();

    while (atual != nullptr) {
        Entidade* pEntidade = atual->getInfo();

        if (!pEntidade->getVivo()) {
            Lista<Entidade>::Elemento* proximo = atual->getProximo();

            Remover(pEntidade);
            atual = proximo;
            proximo = nullptr;
            continue;//skippa Executar()
        }
        
        pEntidade->Executar();

        atual = atual->getProximo();
    }
}