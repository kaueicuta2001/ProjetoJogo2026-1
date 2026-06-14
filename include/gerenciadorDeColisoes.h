#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "cogumelopulante.h"
#include "chao.h"
#include "projetil.h"

#include <iostream>
#include <list>

class GerenciadorDeColisoes {
private:
    std::list<Inimigo*> listaInimigos;
    std::list<Obstaculo*> listaObstaculos;
    std::list<Chao*> listaChao;
    std::list<Projetil*> listaProjeteis;
    Jogador* pJogador;
    Jogador* pJogador2;
public:
    GerenciadorDeColisoes(Jogador* jogador, Jogador* jogador2 = nullptr);
    ~GerenciadorDeColisoes();
    void setJogador2(Jogador* jogador2);
    void IncluirInimigo(Inimigo* inimigo);
    void IncluirObstaculo(Obstaculo* obstaculo);
    void IncluirChao(Chao* chao);
    void IncluirProjetil(Projetil* projetil);
    bool VerificarColisao(Entidade* pe1, Entidade* pe2) const;
    void VerificarColisoes(Jogador* pJogador);
    void TratarColisoesJogsObstacs();
    void TratarColisoesInimigoObstacs();
    void TratarColisoesJogsInimigo();
    void TratarColisoesJogsProjeteis();
    void RemoverInimigoInativo();
    void RemoverObstaculoInativo();
    void RemoverProjetilInativo();
    void Executar();
};