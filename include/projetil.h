#pragma once

#include "entidade.h"

class Jogador;

class Projetil : public Entidade
{
private:
    int dano;
    sf::Vector2f direcaoTiro; // Vetor de direção bidirecional normalizado
public:
    Projetil(int id, sf::Vector2f pos, sf::Vector2f dir, int dano);
    ~Projetil();

    void Mover();
    void AumentarDano();
    int getDano() const;
    void Danificar(Jogador* pJogador);

    void Executar();
    void Salvar();
};