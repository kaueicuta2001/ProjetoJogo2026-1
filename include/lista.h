#pragma once

template <class TL>
class Lista
{
public:
    class Elemento
    {
    private:
        TL* pInfo;
        Elemento* pProximo;

    public:
        Elemento(TL* info)
        {
            pInfo = info;
            pProximo = nullptr;
        }

        ~Elemento()
        {
            if (pInfo != nullptr)
            {
                delete pInfo;
            }
            pInfo = nullptr;
            pProximo = nullptr;
        }

        void setProximo(Elemento* proximo)
        {
            pProximo = proximo;
        }

        Elemento* getProximo() const
        {
            return pProximo;
        }

        TL* getInfo() const
        {
            return pInfo;
        }
    };

private:
    Elemento* pPrimeiro;
    Elemento* pUltimo;
    unsigned int quantidade;

public:
    Lista()
    {
        pPrimeiro = nullptr;
        pUltimo = nullptr;
        quantidade = 0;
    }

    ~Lista()
    {
        esvaziar();
    }

    void Incluir(TL* info)
    {
        if (info == nullptr) return;

        Elemento* novo = new Elemento(info);

        if (pPrimeiro == nullptr)
        {
            pPrimeiro = novo;
            pUltimo = novo;
        }
        else
        {
            pUltimo->setProximo(novo);
            pUltimo = novo;
        }
        quantidade++;
    }

    void remover(TL* info)
    {
        if (info == nullptr || pPrimeiro == nullptr) return;

        Elemento* atual = pPrimeiro;
        Elemento* anterior = nullptr;

        while (atual != nullptr && atual->getInfo() != info)
        {
            anterior = atual;
            atual = atual->getProximo();
        }

        if (atual == nullptr) return;

        if (atual == pPrimeiro)
        {
            pPrimeiro = atual->getProximo();
        }
        else
        {
            anterior->setProximo(atual->getProximo());
        }

        if (atual == pUltimo)
        {
            pUltimo = anterior;
        }

        delete atual;
        quantidade--;
    }

    void esvaziar()
    {
        Elemento* atual = pPrimeiro;

        while (atual != nullptr)
        {
            Elemento* aux = atual->getProximo();
            delete atual;
            atual = aux;
        }

        pPrimeiro = nullptr;
        pUltimo = nullptr;
        quantidade = 0;
    }

    Elemento* getPrimeiro() const
    {
        return pPrimeiro;
    }

    unsigned int getQuantidade() const
    {
        return quantidade;
    }

    void Percorrer()
    {
        Elemento* atual = pPrimeiro;

        while (atual != nullptr)
        {
            TL* info = atual->getInfo();
            info->Executar();
            atual = atual->getProximo();
        }
    }
};
