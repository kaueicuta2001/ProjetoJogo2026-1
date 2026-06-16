#pragma once
#include "Ente.h"
#include <string>
#include <SFML/Graphics.hpp>

class Entidade : public Ente
{
    protected:
        bool vivo;
        std::string nome;
        sf::Vector2f vel;
        float gravidade;
        bool noChao;

    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();

        virtual void setPosicao(sf::Vector2f pos);
        virtual sf::Vector2f getPosicao() const;
        virtual sf::Vector2f getTamanho() const;

        virtual bool getVivo() const;
        virtual void Desativar();
        void InicializarSprite(sf::Texture& textura);

        void AplicarGravidade();
        void Gravitropismo();
        
        // Física e Movimento
        void SetNoChao(bool chao);
        bool getNoChao() const;
        void setVelY(float vY);
        void setVelX(float vX);
        float getVelY() const;

        std::string getNome() const;
        sf::Sprite getSprite() const { return sprite; }

        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};