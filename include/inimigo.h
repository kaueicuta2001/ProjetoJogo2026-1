#pragma once

#include "personagem.h"

class Jogador;

class Inimigo : public Personagem
{
    protected:
        int nivel_maldade;
        bool colideObstaculo;
    public:
        Inimigo(int id, sf::Vector2f pos);
        virtual ~Inimigo();
        virtual void Mover() = 0;
        virtual void AprimorarMaldade() = 0;
        virtual void Danificar(Jogador* jogador) = 0;
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
        bool getColideObstaculo() const;
};
