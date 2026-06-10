#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase1::Fase1(int id, Jogador* pJogador) :
Fase(id, pJogador),
maxVespas(5),         
maxCogumelos(5)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    CriarObstaculos();
    CriarInimigos();
    if (!textura.loadFromFile("../assets/fase1BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    CriarCenario();
}

Fase1::~Fase1()
{
    pJogador = nullptr;
    listaEntidades.Esvaziar();
}

void Fase1::CriarVespas()
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

void Fase1::CriarCogumelosPulantes()
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

void Fase1::CriarInimigos()
{
    CriarBesouros();
    CriarVespas(); 
}

void Fase1::CriarObstaculos()
{
    CriarPlataformas();
    CriarChao();
    CriarCogumelosPulantes();
}

void Fase1::Executar()
{
    Desenhar(); // Desenha o Fundo primeiro
    pJogador->Executar(); // Executa o Jogador
    listaEntidades.Percorrer(); // Executa (Move/Desenha) Entidades
    gerenciadorColisoes.Executar(); // Verifica Colisões
    TratarEventos(); // Trata eventos do frame atual
}

