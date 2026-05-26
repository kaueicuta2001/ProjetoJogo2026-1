#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"

class GerenciadorDeColisoes {
private:
    Lista<Inimigo>* pListaInimigos;
    Lista<Obstaculo>* pListaObstaculos;

public:
    GerenciadorDeColisoes();
    ~GerenciadorDeColisoes();
    void setListas(Lista<Inimigo>* pInimigos, Lista<Obstaculo>* pObstaculos);
    void VerificarColisoes(Jogador* pJogador);
};