#pragma once

#include "entidade.h"

class Jogador;

class Projetil : public Entidade
{
private:
    sf::Vector2f vel;
    int dano;
    int direcao; // 1 = direita, -1 = esquerda

public:
    Projetil(int id, sf::Vector2f pos, int direcao, int dano = 5);
    ~Projetil();

    void Mover();
    void AumentarDano();
    int getDano() const;
    void Danificar(Jogador* pJogador);
    void Executar();
    void Salvar();
};