#pragma once

#include <iostream>

#include "fase.h"
#include "vespa.h"
#include "cogumelopulante.h"

class Fase1 : public Fase
{
private:
    int maxVespas;
    int maxCogumelos;
public:
    Fase1(int id, Jogador* pJogador, Jogador* pJogador2 = nullptr);
    ~Fase1();
    
    void CriarVespas();
    void CriarCogumelosPulantes();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
};