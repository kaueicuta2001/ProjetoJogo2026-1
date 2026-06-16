#pragma once
#include "fase.h"

#include "ReiBesouro.h"

class Fase2 : public Fase
{
private:
    int maxVespas;
    int maxReiBesouro;
    std::vector<ReiBesouro*> vReiBesouros; // Vetor para armazenar os ponteiros dos Rei Besouros
public:
    Fase2(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr);
    ~Fase2();

    void CriarCenario();
    void CriarInimigos() override;
    void CriarObstaculos() override;

    // Funções específicas da Fase 2
    void CriarVespas();
    void CriarCogumelosPulantes();
    void CriarReiBesouro();
    void CriarObstDificilFase2();

    void VerificarAtirarReiBesouro();

    void Executar() override;
};