#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;
using namespace TheFrog::Fases;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Listas;
using namespace TheFrog::Entidades::Obstaculos;
using namespace TheFrog::Entidades::Personagens;

Fase1::Fase1(int id, Jogador* pJogador, Jogador* pJogador2) :
Fase(id, pJogador, pJogador2),
maxVespas(5),         
maxLamalentos(5)
{
    if (!textura.loadFromFile("../assets/fase1BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    CriarCenario();
    CriarObstaculos();
    CriarInimigos();   
}

Fase1::~Fase1()
{
}

void Fase1::CriarVespas()
{
    float posicoesY[5] = {575.f, 475.f, 375.f, 275.f, 375.f};

    int numVespas = (rand() % (maxVespas - 2)) + 3; 
    for (int i = 0; i < numVespas; i++)
    {
        Vespa* pVespa = new Vespa(i + 30, Vector2f(160.f + (i * 150.f), posicoesY[i]), 60.f);
        listaEntidades.Incluir(pVespa);
        gerenciadorColisoes.IncluirInimigo(pVespa);
    }
}

void Fase1::CriarLamasLentas()
{
    int numLamas = (rand() % (maxLamalentos - 2)) + 3;

    float posicoesX[5] = {250.f, 550.f, 850.f, 400.f, 700.f};
    float altura = Ente::pGG->getWindow()->getSize().y - 33.f;

    for (int i = 0; i < numLamas; i++)
    {
        LamaLento* pLama = new LamaLento(i + 50, Vector2f(posicoesX[i], altura));
        listaEntidades.Incluir(pLama);
        gerenciadorColisoes.IncluirObstaculo(pLama);
    }
}

void Fase1::CriarInimigos()
{
    CriarVespas();
    CriarBesouros();
}

void Fase1::CriarObstaculos()
{
    CriarPlataformas();
    CriarLamasLentas();
}

void Fase1::Executar()
{
    Desenhar();

    gerenciadorColisoes.Executar();
    listaEntidades.Percorrer();
    Fase::Executar();
}