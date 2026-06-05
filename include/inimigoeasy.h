#pragma once

#include "inimigo.h"

class Jogador;

class InimigoEasy : public Inimigo
{
private:
    float distancia;
    float limiteDir;
    float limiteEsq;
    int direcao;
public:
    InimigoEasy(int id, sf::Vector2f pos, float dist);
    ~InimigoEasy();
    void Mover();
    void AprimorarMaldade();
    void Danificar(Jogador* jogador);
    void Executar();
    void Salvar();
};
