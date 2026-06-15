#pragma once

#include "entidade.h"
#include <SFML/Graphics.hpp>

class Jogador;

class Projetil : public Entidade
{
private:
    sf::Vector2f vel;
    int dano;
    sf::Vector2f direcaoTiro; // Vetor de direção bidirecional normalizado

public:
    Projetil(int id, sf::Vector2f pos, sf::Vector2f dirNormalizada, int dano);
    ~Projetil();

    void Mover();
    void AumentarDano();
    int getDano() const;
    void Danificar(Jogador* pJogador);

    void Executar() override;
    void Salvar() override;
};