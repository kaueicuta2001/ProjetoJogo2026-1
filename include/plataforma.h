#pragma once

#include "obstaculo.h"

class Plataforma : public Obstaculo
{
private:
    int altura;
public:
    Plataforma(int altura, bool danoso, int x, int y, int id);
    ~Plataforma();
    void Executar();
    void Salvar();
};
