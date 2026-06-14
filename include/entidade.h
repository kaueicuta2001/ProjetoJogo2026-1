#pragma once
#include "Ente.h"

class Entidade : public Ente
{
    protected:
        bool vivo;
        std::string nome;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();
        void setPosicao(sf::Vector2f pos);
        const sf::Vector2f getPosicao();
        const sf::Vector2f getTamanho();
        bool getVivo() const;
        virtual void Desativar();
        
        void InicializarSprite(sf::Texture& textura);
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};