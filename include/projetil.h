#pragma once

#include "entidade.h"

class Jogador;
class ReiBesouro;

class Projetil : public Entidade
{
private:
    int dano;
    sf::Vector2f direcaoTiro; 
    ReiBesouro* pReiBesouro; 
public:
    Projetil(int id, sf::Vector2f pos, ReiBesouro* rei);
    ~Projetil();

    void Mover();
    void AumentarDano();
    void AumentarDanoReiBesouro();
    void Danificar(Jogador* pJogador);

    void Executar();
    void Salvar();
};