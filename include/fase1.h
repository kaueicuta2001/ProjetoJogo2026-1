#pragma once
#include "fase.h"

class Fase1 : public Fase
{
private:
    int maxVespas;
    int maxCogumelos;

public:
    Fase1(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr);
    ~Fase1();

    void CriarCenario() override;
    void CriarInimigos() override;
    void CriarObstaculos() override;

    // Funções específicas da Fase 1
    void CriarVespas();
    void CriarCogumelosPulantes();
};