#pragma once

#include "inimigo.h"

class Jogador;

class Besouro : public Inimigo
{
private:
    float distancia;
    float limiteDir;
    float limiteEsq;
    int direcao;
public:
    Besouro(int id, sf::Vector2f pos, float dist);
    ~Besouro();
    void Mover();
    void AprimorarMaldade();
    void Danificar(Jogador* jogador);
    void Executar();
    void Salvar();
};
