#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase1::Fase1(int id, Jogador* pJogador, Jogador* pJogador2) :
Fase(id, pJogador, pJogador2),
maxVespas(5),         
maxCogumelos(5)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());

    if (!textura.loadFromFile("../assets/fase1BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    CriarCenario();
    CriarObstaculos();
    CriarInimigos();   
    CriarChao();
}

Fase1::~Fase1()
{
    listaEntidades.Esvaziar();
}

void Fase1::CriarVespas()
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
    CriarVespas();
    CriarBesouros();
}

void Fase1::CriarObstaculos()
{
    CriarPlataformas();
    CriarCogumelosPulantes();
}

void Fase1::Executar()
{
    Desenhar();

if (pJogador) {
        sf::FloatRect bounds = pJogador->getSprite().getGlobalBounds();
        sf::Vector2f escala = pJogador->getSprite().getScale();
        std::cout << "[DEBUG JOGADOR] Pos: (" << pJogador->getPosicao().x << ", " << pJogador->getPosicao().y 
                  << ") | Bounds: (" << bounds.width << "x" << bounds.height 
                  << ") | Escala: (" << escala.x << ", " << escala.y << ")" << std::endl;
    }

    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
    Fase::Executar();
}