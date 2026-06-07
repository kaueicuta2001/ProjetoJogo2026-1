#pragma once

#include "obstaculo.h"

class Jogador;

class CogumeloPulante : public Obstaculo
{
private:
    float forcaimpulso;
public:
    CogumeloPulante(int id, sf::Vector2f pos, bool danoso);
    ~CogumeloPulante();
    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};
