#pragma once

#include <SFML/Graphics.hpp>
#include "personagem.h"

class Jogador : public Personagem
{
    private:
        int pontos;
    public:
        Jogador(int id, sf::Vector2f pos, int num_vidas);
        ~Jogador();
        void Mover();
        void Executar();
        void Salvar();
};