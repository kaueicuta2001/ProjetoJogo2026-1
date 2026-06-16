#include "fase2.h"
#include "gerenciadorgrafico.h"
#include "vespa.h"
#include "cogumelopulante.h"
#include "reibesouro.h"
#include "chao.h"
#include <iostream>

using namespace sf;
using namespace std;

Fase2::Fase2(int id, Jogador* pJogador, Jogador* pJogador2) :
Fase(id, pJogador, pJogador2),
maxVespas(5),         
maxReiBesouro(5)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    CriarObstaculos();
    CriarInimigos();
    if (!textura.loadFromFile("../assets/backgroundfase2.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    CriarCenario();
}

Fase2::~Fase2()
{
    listaEntidades.Esvaziar();
}

void Fase2::CriarVespas()
{
    float posicoesY[5] = {600.f, 500.f, 400.f, 300.f, 400.f};

    int numVespas = (rand() % (maxVespas - 2)) + 3; 
    for (int i = 0; i < numVespas; i++)
    {
        Vespa* pVespa = new Vespa(i + 30, Vector2f(160.f + (i * 150.f), posicoesY[i]), 60.f);
        listaEntidades.Incluir(pVespa);
        gerenciadorColisoes.IncluirInimigo(pVespa);
    }
}

void Fase2::CriarReiBesouro()
{
    float posicoesX[5] = {200.f, 450.f, 700.f, 950.f, 600.f};

    int numReiBesouro = (rand() % (maxReiBesouro - 2)) + 3; 
    for (int i = 0; i < numReiBesouro; i++)
    {
        ReiBesouro* pReiBesouro = new ReiBesouro(i + 70, Vector2f(posicoesX[i % 5], 200.f), pJogador, pJogador2);
        listaEntidades.Incluir(pReiBesouro);
        vReiBesouros.push_back(pReiBesouro); // Armazena o ponteiro do Rei Besouro no vetor
        gerenciadorColisoes.IncluirInimigo(pReiBesouro);
    }
}

void Fase2::CriarObstDificilFase2()
{
    //CriarObstDificil();
}

void Fase2::CriarCenario()
{
    sprite.setTexture(textura);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );

    Chao* chao = new Chao(1, Vector2f(0.f, tamanho.y - 32.f), false);
    listaEntidades.Incluir(chao);
    gerenciadorColisoes.IncluirChao(chao);
}

void Fase2::CriarInimigos()
{
    CriarVespas();
    CriarBesouros();
    CriarReiBesouro();
}

void Fase2::CriarObstaculos()
{
    CriarPlataformas();
    CriarObstDificilFase2();
}

void Fase2::VerificarAtirarReiBesouro()
{
    for(ReiBesouro* rei : vReiBesouros)
    {
        if (rei->getAtirar())
        {
            Projetil* pProjetil = new Projetil(100 + rei->getId(), rei->getPosicao(), rei->getDirecaoTiro(), rei->getDano());
            listaEntidades.Incluir(pProjetil);
            gerenciadorColisoes.IncluirProjetil(pProjetil);
            rei->AprimorarMaldade();
        }
    }
}

void Fase2::Executar()
{
    Desenhar();
    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
    Fase::Executar();
}