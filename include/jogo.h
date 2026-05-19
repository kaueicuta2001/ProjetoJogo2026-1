#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Jogo
{
    public:
        Jogo();
        ~Jogo();
        void executar();
    private:
        sf::RenderWindow* janela;
        sf::Event evento;
};