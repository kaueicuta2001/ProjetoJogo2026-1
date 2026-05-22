#pragma once

#include <SFML/Graphics.hpp>
#include "personagem.h"

class Jogador : public Personagem
{
    private:
        int pontos;
        void Inicializar();
    public:
        Jogador(int id, sf::Vector2f pos, int num_vidas);
        ~Jogador();
        void Mover();
        void Desenhar(sf::RenderWindow& janela);
        void Executar();
        void Salvar();
};