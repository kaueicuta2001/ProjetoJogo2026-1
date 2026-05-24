#pragma once

#include "inimigo.h"

class InimigoEasy : public Inimigo
{
private:
    float raio;
public:
    InimigoEasy(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade, float rraio);
    ~InimigoEasy();
    void Mover();
    void Executar();
    void Salvar();
};
