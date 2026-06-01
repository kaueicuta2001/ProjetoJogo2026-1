#pragma once

#include "fase.h"

class Fase1 : public Fase
{
private:
    int maxInimigosEasy;
    int maxPlataformas;
public:
    Fase1(int id, Jogador* pJogador);
    ~Fase1();
    void CriarInimigosEasy();
    void CriarPlataformas();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
    void Salvar();
};