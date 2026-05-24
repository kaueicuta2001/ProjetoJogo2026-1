#pragma once

#include "obstaculo.h"

class Plataforma : public Obstaculo
{
private:
    int altura;
public:
    Plataforma(int id, sf::Vector2f pos, bool danoso, int altura);
    ~Plataforma();
    void Executar();
    void Salvar();
};
