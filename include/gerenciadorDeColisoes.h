#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"

#include <iostream>
#include <list>

class GerenciadorDeColisoes {
private:
    std::list<Inimigo*> listaInimigos;
    std::list<Obstaculo*> listaObstaculos;

public:
    GerenciadorDeColisoes();
    ~GerenciadorDeColisoes();
    void IncluirInimigo(Inimigo* inimigo);
    void IncluirObstaculo(Obstaculo* obstaculo);
    void VerificarColisoes(Jogador* pJogador);
    void RemoverInimigoInativo();
    void RemoverObstaculoInativo();
};