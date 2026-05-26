#pragma once

#include "obstaculo.h"

class Plataforma : public Obstaculo
{
private:
    int tempo;
public:
    Plataforma(int id, sf::Vector2f pos, bool danoso);
    ~Plataforma();

    //void obstaculizar();
    void Executar();
    void Salvar();
};
