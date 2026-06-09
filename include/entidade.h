#pragma once
#include "Ente.h"

class Entidade : public Ente
{
    protected:
        bool vivo;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();
        virtual void setPosicao(sf::Vector2f pos);
        virtual sf::Vector2f getPosicao();
        virtual sf::Vector2f getTamanho();
        virtual bool getVivo();
        virtual void Desativar();
        void InicializarSprite(sf::Texture& textura);
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
