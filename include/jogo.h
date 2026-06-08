#pragma once

#include "gerenciadorgrafico.h"
#include "jogador.h"
#include "menu.h"
#include "fase.h"
#include "fase1.h"
#include "gerenciadorDeColisoes.h"

class Jogo
{
private:
    int opcaoSelecionada;
    GerenciadorGrafico* GG;
    Jogador* pJogador;
    Menu* menu;
    Fase* faseAtual;
public:
    Jogo();
    ~Jogo();
    void Executar();
};
