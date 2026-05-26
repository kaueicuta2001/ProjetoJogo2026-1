#pragma once

#include "personagem.h"

class Jogador : public Personagem
{
    private:
        int pontos;
    public:
        Jogador(int id, sf::Vector2f pos);
        ~Jogador();
        void Mover();
        void Executar();
        void Salvar();
};
