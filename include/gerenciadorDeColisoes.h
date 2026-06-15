#pragma once

#include "jogador.h"
#include "inimigo.h"
#include "obstaculo.h"
#include "chao.h"
#include "projetil.h"
#include <list>

class GerenciadorDeColisoes {
private:
    std::list<Inimigo*> listaInimigos;
    std::list<Obstaculo*> listaObstaculos;
    std::list<Chao*> listaChao;
    std::list<Projetil*> listaProjeteis;

public:
    Jogador* pJogador;
    Jogador* pJogador2;

    GerenciadorDeColisoes(Jogador* pJ = nullptr, Jogador* pJ2 = nullptr);
    ~GerenciadorDeColisoes();

    void setJogador(Jogador* pJ);
    void setJogador2(Jogador* pJ2);

    void IncluirInimigo(Inimigo* pI);
    void IncluirObstaculo(Obstaculo* pO);
    void IncluirChao(Chao* pC);
    void IncluirProjetil(Projetil* pP);

    void Executar();
    bool VerificarColisao(Entidade* ent1, Entidade* ent2);

    void RemoverInimigoInativo();
    void RemoverObstaculoInativo();
    void RemoverProjetilInativo();
};