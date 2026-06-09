#pragma once

#include <iostream>

#include "fase.h"
#include "vespa.h"
#include "cogumelopulante.h"

class Fase1 : public Fase
{
private:
    int maxBesouros;
    int maxVespas;
    int maxPlataformas;
    int maxCogumelos;

public:
    Fase1(int id, Jogador* pJogador);
    ~Fase1();
    
    void InicializarBG();
    void CriarBesouros();
    void CriarVespas();
    void CriarChao();
    void CriarPlataformas();
    void CriarCogumelosPulantes();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
    void Salvar();
};