#pragma once

template <class TL>
class Lista {
    public:
        class Elemento {
            private:
                TL* pInfo;
                Elemento* pProximo;

            public:
                Elemento(TL* info) {
                    pInfo = info;
                    pProximo = nullptr;
                }
                
                ~Elemento() {
                    if (pInfo != nullptr) {
                        delete pInfo;
                    }
                    pInfo = nullptr;
                    pProximo = nullptr;
                }

                void setProximo(Elemento* proximo) { pProximo = proximo; }
                Elemento* getProximo() const { return pProximo; }
                TL* getInfo() const { return pInfo; }
            };

    private:
        Elemento* pPrimeiro;
        Elemento* pUltimo;
        unsigned int quantidade;

    public:
        Lista() {
            pPrimeiro = nullptr;
            pUltimo = nullptr;
            quantidade = 0;
        }

        ~Lista() {
            Esvaziar();
        }

        void Incluir(TL* info) {
            if (info == nullptr) return;

            Elemento* novo = new Elemento(info);

            if (pPrimeiro == nullptr) {
                pPrimeiro = novo;
                pUltimo = novo;
            } else {
                pUltimo->setProximo(novo);
                pUltimo = novo;
            }
            quantidade++;
        }

        void Remover(TL* info) {
            if (info == nullptr || pPrimeiro == nullptr) return;

            Elemento* atual = pPrimeiro;
            Elemento* anterior = nullptr;

            //Loop para encontrar o nó que carrega a entidade parametro(info)
            while (atual != nullptr && atual->getInfo() != info) {
                anterior = atual;
                atual = atual->getProximo();
            }

            // Se não encontrou a entidade na lista, não faz nada
            if (atual == nullptr) return;
            
            // CASO A: O elemento é o PRIMEIRO da lista
            if (atual == pPrimeiro) {
                pPrimeiro = atual->getProximo();
            } 
            // CASO B: O elemento está no MEIO da lista
            else {
                anterior->setProximo(atual->getProximo());
            }

            // CASO C: O elemento é o ÚLTIMO da lista
            if (atual == pUltimo) {
                pUltimo = anterior;
            }

            delete atual; 
            quantidade--;
        }

        void Esvaziar() {
            Elemento* atual = pPrimeiro;
            while (atual != nullptr) {
                Elemento* aux = atual->getProximo();
                delete atual; 
                atual = aux;
            }
            pPrimeiro = nullptr;
            pUltimo = nullptr;
            quantidade = 0;
        }

        Elemento* getPrimeiro() const { 
            return pPrimeiro; 
        }

        unsigned int getQuantidade() const { 
            return quantidade; 
        }
};