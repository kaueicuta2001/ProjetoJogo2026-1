#pragma once

#include <string>
#include "entidade.h"
#include <iostream>

class Personagem : public Entidade
{
protected:
    int num_vidas;
    float gravidade;
    bool noChao;
    int dano;

public:
    Personagem(int id, sf::Vector2f pos);
    ~Personagem();

    virtual void Mover() = 0;
    void SetNoChao(bool chao);
    bool getNoChao();
    void PerderVidas(int danos);
    int getVidas() const;
    int getDano() const; 
};