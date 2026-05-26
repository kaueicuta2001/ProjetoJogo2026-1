#pragma once

#include "gerenciadorgrafico.h"
#include "lista.h"
#include "jogador.h"
#include "plataforma.h"
#include "inimigoeasy.h"
#include "gerenciadorDeColisoes.h"

class Jogo
{
private:
    GerenciadorGrafico* GG;
    Lista<Inimigo> listaInimigos;
    Lista<Obstaculo> listaObstaculos;
    GerenciadorDeColisoes gerenciadorColisoes;
    Jogador* pJogador;

public:
    Jogo();
    ~Jogo();
    void InstanciarEntidades();
    void Executar();
};
