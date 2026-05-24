#pragma once

#include "gerenciadorgrafico.h"
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
        GerenciadorGrafico* pGG;
        sf::Event evento;
        Jogador jogador;
        Plataforma plataforma;
        InimigoEasy inimigoeasy;
    public:
        Jogo();
        ~Jogo();
        void Executar();
};