#pragma once

#include "gerenciadorgrafico.h"
#include "lista.h"
#include "listaentidades.h"
#include "jogador.h"
#include "plataforma.h"
#include "chao.h"
#include "besouro.h"
#include "vespa.h"
#include "reibesouro.h"
#include "fase.h"
#include "fase1.h"
#include "gerenciadorDeColisoes.h"

class Jogo
{
private:
    GerenciadorGrafico* GG;
    Jogador* pJogador;
    Fase *faseAtual;

public:
    Jogo();
    ~Jogo();
    void InstanciarEntidades();
    void Executar();
};
