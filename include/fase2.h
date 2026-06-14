#pragma once

#include <iostream>

#include "fase.h"
#include "vespa.h"
#include "reibesouro.h"
#include "cogumelopulante.h"

class Fase2 : public Fase
{
private:
    int maxVespas;
    int maxCogumelos;
    int maxReiBesouro;
public:
    Fase2(int id, Jogador* pJogador, Jogador* pJogador2 = nullptr);
    ~Fase2();
    
    void CriarVespas();
    void CriarCogumelosPulantes();
    void CriarReiBesouro();
    void CriarObstDificilFase2();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
};