#pragma once

#include "entidade.h"

class Obstaculo : public Entidade
{
protected:
    bool danoso;

public:
    Obstaculo(int id, sf::Vector2f pos, bool danoso);
    ~Obstaculo();
    virtual void Executar() = 0;
    virtual void Salvar() = 0;
};
