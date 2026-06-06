#pragma once

#include "fase.h"

class Fase1 : public Fase
{
private:
    int maxBesouros;
    int maxVespas;
    int maxPlataformas;
    sf::Vector2f tamBG;

public:
    Fase1(int id, Jogador* pJogador);
    ~Fase1();
    
    void InicializarBG();
    void CriarBesouros();
    void CriarVespas();
    void CriarChao();
    void CriarPlataformas();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
    void Salvar();
};