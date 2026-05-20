#pragma once

#include "inimigo.h"

class InimigoEasy : public Inimigo
{
private:
    float raio;
public:
    InimigoEasy(float raio, int nivel_maldade, int num_vidas, int x, int y, int id);
    ~InimigoEasy();
    void Executar();
    void Salvar();
};
