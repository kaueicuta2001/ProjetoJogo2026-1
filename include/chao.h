#pragma once

#include "obstaculo.h"

class Chao : public Obstaculo
{
private:
    float altura;
    float largura;
public:
    Chao(int id, sf::Vector2f pos, int danoso);
    ~Chao();
    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};
