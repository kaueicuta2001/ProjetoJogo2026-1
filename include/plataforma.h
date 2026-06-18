#pragma once

#include "obstaculo.h"

class Jogador;

class Plataforma : public Obstaculo
{
private:
    int tempo;
public:
    Plataforma(int id, sf::Vector2f pos);
    ~Plataforma();

    void DeslizarJogador(Jogador* pJogador);
    void Obstaculizar(Jogador* pJogador);
    void Executar();
    void Salvar();
};