#pragma once

#include "inimigo.h"

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
    void Executar();
    void Salvar();
};
