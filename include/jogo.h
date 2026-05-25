#pragma once

#include "gerenciadorgrafico.h"
#include "listaentidades.h"
#include "jogador.h"
#include "plataforma.h"
#include "obstdificil.h"
#include "obstmedio.h"
#include "inimigoeasy.h"
#include "inimigomedio.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Jogo
{
    private:
        GerenciadorGrafico* GG;
        ListaEntidades listaEnts;
    public:
        Jogo();
        ~Jogo();
        void InstanciarEntidades();
        void Executar();
};