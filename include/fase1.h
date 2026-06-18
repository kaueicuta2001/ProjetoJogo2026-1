#pragma once
#include "fase.h"
#include "vespa.h"
#include "lamalento.h"

class Fase1 : public Fase
{
private:
    int maxVespas;
    int maxLamalentos;
public:
    Fase1(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr);
    ~Fase1();

    void CriarInimigos();
    void CriarObstaculos();

    // Funções específicas da Fase 1
    void CriarVespas();
    void CriarLamasLentas();

    void Executar() override;
};