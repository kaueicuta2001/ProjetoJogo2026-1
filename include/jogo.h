#pragma once

#include "gerenciadorgrafico.h"
#include "lista.h"
#include "listaentidades.h"
#include "jogador.h"
#include "plataforma.h"
#include "inimigoeasy.h"
#include "fase1.h"
#include "gerenciadorDeColisoes.h"

class Jogo
{
private:
    GerenciadorGrafico* GG;
    ListaEntidades listaEntidades;
    GerenciadorDeColisoes gerenciadorColisoes;
    Jogador* pJogador;
    Fase *faseAtual;

public:
    Jogo();
    ~Jogo();
    void InstanciarEntidades();
    void Executar();
};
