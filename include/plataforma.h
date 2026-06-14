#pragma once

#include "obstaculo.h"
#include "jogador.h"

class Plataforma : public Obstaculo
{
private:
    int tempo;
public:
    Plataforma(int id, sf::Vector2f pos, bool danoso);
    ~Plataforma();

    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};
