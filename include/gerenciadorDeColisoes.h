#pragma once

#include "jogador.h"
#include "inimigo.h"
#include "obstaculo.h"
#include "chao.h"
#include "projetil.h"
#include <list>

class GerenciadorDeColisoes {
private:
    sf::Vector2f intersecao;
    Jogador* pJogador;
    Jogador* pJogador2;
    std::list<Inimigo*> listaInimigos;
    std::list<Obstaculo*> listaObstaculos;
    std::list<Chao*> listaChao;
    std::list<Projetil*> listaProjeteis;
    int totalColisoes;
public:

    GerenciadorDeColisoes(Jogador* pJ = nullptr, Jogador* pJ2 = nullptr);
    ~GerenciadorDeColisoes();

    void getTotalColisoes() const;    
    void IncluirInimigo(Inimigo* pI);
    void IncluirObstaculo(Obstaculo* pO);
    void IncluirChao(Chao* pC);
    void IncluirProjetil(Projetil* pP);
    
    bool VerificarColisao(Entidade* ent1, Entidade* ent2);

    void TratarColisoesPersChao();
    void TratarColisoesJogsObstacs();
    void TratarColisoesJogsInimgs();
    void TratarColisoesJogsProjeis();
    void TratarColisoesInimgsObstacs();

    void Executar();

    void RemoverInimigoInativo();
    void RemoverObstaculoInativo();
    void RemoverProjetilInativo();
};