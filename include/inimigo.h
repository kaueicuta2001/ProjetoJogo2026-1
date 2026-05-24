#pragma once

#include "personagem.h"

class Inimigo : public Personagem
{
    protected:
        int nivel_maldade;
    public:
        Inimigo(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade);
        virtual ~Inimigo();
        virtual void Mover() = 0;
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
