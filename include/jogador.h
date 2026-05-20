#pragma once

#include <SFML/Graphics.hpp>
#include "personagem.h"

class Jogador : public Personagem
{
    private:
        int pontos;
        sf::RectangleShape corpo;
    public:
        Jogador(int num_vidas, int x, int y, int id, int pontos);
        ~Jogador();
        void Desenhar(sf::RenderWindow& janela);
        void Executar();
        void Salvar();
};