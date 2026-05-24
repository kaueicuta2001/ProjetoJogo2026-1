#pragma once

#include "obstaculo.h"

class ObstDificil : public Obstaculo
{
private:
    short int danosidade;
public:
    ObstDificil(int id, sf::Vector2f pos, bool danoso, short int danosidade);
    ~ObstDificil();
    void Executar();
    void Salvar();
};
