#pragma once

#include <iostream>

#include "fase.h"
#include "cactopulante.h"
#include "ReiBesouro.h"

class Fase2 : public Fase
{
private:
    int maxVespas;
    int maxReiBesouro;
    std::vector<ReiBesouro*> vReiBesouros; // Vetor para armazenar os ponteiros dos Rei Besouros
public:
    Fase2(int id, Jogador* pJogador, Jogador* pJogador2);
    ~Fase2();

    void CriarCenario();
    void CriarInimigos() override;
    void CriarObstaculos() override;

    // Funções específicas da Fase 2
    void CriarReiBesouro();
    void CriarCactosPulantes();

    void VerificarAtirarReiBesouro();

    void Executar() override;
};