#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GerenciadorGrafico;

class Ente
{
    protected:
        int id;
        static GerenciadorGrafico* pGG;
        sf::Texture textura;
        sf::Sprite sprite;
        sf::Vector2f posicao;
        sf::Vector2f tamanho;

    public:
        Ente(int id);
        virtual ~Ente();
        static void setGG(GerenciadorGrafico* gg);
        virtual void Executar() = 0;
        void Desenhar();
};
