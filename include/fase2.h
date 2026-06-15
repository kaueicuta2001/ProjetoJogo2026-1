#pragma once
#include "fase.h"

class Fase2 : public Fase
{
private:
    int maxVespas;
    int maxCogumelos;
    int maxReiBesouro;

public:
    Fase2(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr);
    ~Fase2();

    void CriarCenario() override;
    void CriarInimigos() override;
    void CriarObstaculos() override;

    // Funções específicas da Fase 2
    void CriarVespas();
    void CriarCogumelosPulantes();
    void CriarReiBesouro();
    void CriarObstDificilFase2();
};