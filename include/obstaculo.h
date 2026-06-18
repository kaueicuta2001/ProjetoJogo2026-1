#pragma once

#include "entidade.h"

class Jogador;

class Obstaculo : public Entidade
{
protected:
    bool danoso;
public:
    Obstaculo(int id, sf::Vector2f pos);
    ~Obstaculo();

    virtual void Obstaculizar(Jogador* pJogador) = 0;
    virtual void Executar() = 0;
    virtual void Salvar() = 0;
};
