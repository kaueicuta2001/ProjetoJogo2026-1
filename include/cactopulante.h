#pragma once
#include "obstaculo.h"

class Jogador;

class CactoPulante : public Obstaculo {
private:
    short int danosidade;
    bool espinhosFlamejantes; 
    int vidaJogador;
public:
    CactoPulante(int id, sf::Vector2f pos);
    ~CactoPulante();

    void FlamejarEspinhos();
    void Obstaculizar(Jogador* pJogador) override;
    void Danificar(Jogador* pJogador);
    void Executar() override;
    void Salvar() override;
};