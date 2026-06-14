#include "fase2.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase2::Fase2(int id, Jogador* pJogador, Jogador* pJogador2) :
Fase(id, pJogador, pJogador2),
maxVespas(5),         
maxCogumelos(5)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    CriarObstaculos();
    CriarInimigos();
    if (!textura.loadFromFile("../assets/fase2BG.png"))
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

    int numVespas = (rand() % (maxVespas - 2)) + 3; // Gera um número aleatório entre 3 e maxVespas
    for (int i = 0; i < numVespas; i++)
    {
        Vespa* pVespa = new Vespa(i + 30, Vector2f(160.f + (i * 150.f), posicoesY[i]), 60.f);
        listaEntidades.Incluir(pVespa);
        gerenciadorColisoes.IncluirInimigo(pVespa);
    }
}

void Fase2::CriarCogumelosPulantes()
{
    int numCogumelos = (rand() % (maxCogumelos - 2)) + 3;

    float posicoesX[5] = {250.f, 550.f, 850.f, 400.f, 700.f};
    float altura = Ente::pGG->getWindow()->getSize().y - 64.f - 32.f;

    for (int i = 0; i < numCogumelos; i++)
    {
        CogumeloPulante* pCogumelo = new CogumeloPulante(i + 50, Vector2f(posicoesX[i], altura), false);
        listaEntidades.Incluir(pCogumelo);
        gerenciadorColisoes.IncluirObstaculo(pCogumelo);
    }
}

void Fase2::CriarInimigos()
{
    CriarBesouros();
    CriarVespas(); 
}

void Fase2::CriarObstaculos()
{
    CriarPlataformas();
    CriarChao();
    CriarCogumelosPulantes();
}

void Fase2::Executar()
{
    Desenhar();
    pJogador->Executar();
    if(pJogador2)
        pJogador2->Executar();
    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
    TratarEventos(); // Trata eventos do frame atual
}

