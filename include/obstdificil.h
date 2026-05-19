#pragma once

#include "obstaculo.h"

class ObstDificil : public Obstaculo
{
private:
    short int danosidade;
public:
    ObstDificil(short int danosidade, bool danoso, int x, int y, int id);
    ~ObstDificil();
    void executar();
    void salvar();
};
