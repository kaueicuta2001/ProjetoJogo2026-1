#pragma once

#include "entidade.h"

class Personagem : public Entidade
{
    protected:
        int num_vidas;
        sf::Vector2f vel;
    public:
        Personagem(int id, sf::Vector2f pos);
        ~Personagem();
        virtual void Mover() = 0;
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
