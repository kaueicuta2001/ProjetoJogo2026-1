#pragma once

#include "fase.h"

class Fase1 : public Fase
{
private:
    int maxBesouros;
    int maxPlataformas;
    sf::Vector2f tamBG;
public:
    Fase1(int id, Jogador* jogador);
    ~Fase1();
    void InicializarBG();
    void CriarBesouros();
    void CriarChao();
    void CriarPlataformas();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
    void Salvar();
};