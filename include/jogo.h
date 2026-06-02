#pragma once

#include "gerenciadorgrafico.h"
#include "lista.h"
#include "jogador.h"
#include "plataforma.h"
#include "chao.h"
#include "inimigoeasy.h"
#include "inimigomedio.h"
#include "bigchief.h"
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
