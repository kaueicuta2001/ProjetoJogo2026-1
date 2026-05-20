#pragma once

#include "plataforma.h"
#include "obstdificil.h"
#include "obstmedio.h"
#include "jogador.h"
#include "inimigoeasy.h"
#include "inimigomedio.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Jogo
{
    private:
        sf::RenderWindow janela;//RenderWindow é a classe que representa a janela do jogo, e é nela que tudo será desenhado.
        //O primeiro parâmetro é o tamanho da janela, e o segundo é o título da janela.
        sf::Event evento;
        Jogador jogador;
        Plataforma plataforma;
        ObstDificil obstdificil;
        ObstMedio obstmedio;
        InimigoEasy inimigoeasy;
        InimigoMedio inimigomedio;
    public:
        Jogo();
        ~Jogo();
        void Executar();
};