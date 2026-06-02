#pragma once

#include "obstaculo.h"

class Chao : public Obstaculo
{
public:
    Chao(int id, sf::Vector2f windowSize);
    ~Chao();

    void Executar();
    void Salvar();
};
