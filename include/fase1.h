#pragma once
#include "fase.h"
#include "vespa.h"
#include "cogumelopulante.h"

class Fase1 : public Fase
{
private:
    int maxVespas;
    int maxCogumelos;
    Plataforma* pPlataforma;
public:
    Fase1(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr);
    ~Fase1();

    void CriarInimigos();
    void CriarObstaculos();

    // Funções específicas da Fase 1
    void CriarVespas();
    void CriarCogumelosPulantes();

    void Executar() override;
};