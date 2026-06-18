#pragma once

#include "obstaculo.h"

class Jogador;

class LamaLento : public Obstaculo
{
private:
    float lentidao;
public:
    LamaLento(int id, sf::Vector2f pos);
    ~LamaLento();
    void LentificarJogador(Jogador* pJogador);
    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};
