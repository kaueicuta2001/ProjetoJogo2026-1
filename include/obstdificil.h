#pragma once

#include "obstaculo.h"

class Jogador;

class ObstDificil : public Obstaculo
{
private:
    short int danosidade;

public:
    ObstDificil(int id, sf::Vector2f pos, bool danoso, short int danosidade);
    ~ObstDificil();
    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};
