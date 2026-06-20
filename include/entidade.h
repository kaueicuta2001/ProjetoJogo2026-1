#pragma once
#include "Ente.h"
#include <string>
#include <SFML/Graphics.hpp>

class Entidade : public Ente
{
    protected:
        bool vivo;
        sf::Vector2f vel;
        float gravidade;
        bool noChao;
        std::string nome;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();

        void setPosicao(sf::Vector2f pos);
        sf::Vector2f getPosicao() const;
        sf::Vector2f getTamanho() const;

        bool getVivo() const;
        void Desativar();

        void AplicarGravidade();
        void Gravitropismo();
        
        // Física e Movimento
        void SetNoChao(bool chao);
        bool getNoChao() const;

        std::string getNome() const;

        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};