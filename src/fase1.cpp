#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase1::Fase1(int id, Jogador* pJogador) :
Fase(id, pJogador),
maxBesouros(5),       
maxVespas(5),         
maxPlataformas(7),
maxCogumelos(5),
tamBG(pGG->getWindow()->getSize())
{
    CriarObstaculos();
    CriarInimigos();
    InicializarBG();
}

Fase1::~Fase1()
{
    pJogador = nullptr;
    listaEntidades.Esvaziar();
}

void Fase1::InicializarBG()
{
    if (!textura.loadFromFile("../assets/fase1BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    sprite.setTexture(textura);
    sprite.setPosition(0.f, 0.f);
    sprite.setScale(
        tamBG.x / textura.getSize().x,
        tamBG.y / textura.getSize().y
    );
}

void Fase1::CriarBesouros()
{
    int numBesouros = (rand() % maxBesouros) + 3; // Gera um número aleatório entre 3 e maxBesouros
    for (int i = 0; i < numBesouros; i++)
    {
        Besouro* pBesouro = new Besouro(i + 10, Vector2f(150.f + (i * 220.f), 650.f), 80.f);
        listaEntidades.Incluir(pBesouro);
        gerenciadorColisoes.IncluirInimigo(pBesouro);
    }
}

void Fase1::CriarVespas()
{
    float posicoesY[5] = {500.f, 400.f, 250.f, 400.f, 500.f};

    int numVespas = (rand() % maxVespas) + 3; // Gera um número aleatório entre 3 e maxVespas
    for (int i = 0; i < numVespas; i++)
    {
        Vespa* pVespa = new Vespa(i + 30, Vector2f(225.f + (i * 150.f), posicoesY[i]), 60.f);
        listaEntidades.Incluir(pVespa);
        gerenciadorColisoes.IncluirInimigo(pVespa);
    }
}

void Fase1::CriarChao()
{
    Chao* pChao = new Chao(0, Vector2f(0.f, Ente::pGG->getWindow()->getSize().y - 32.f), false);
    listaEntidades.Incluir(pChao);
    gerenciadorColisoes.IncluirObstaculo(pChao);
}

void Fase1::CriarPlataformas()
{
    float posicoesY[7] = {600.f, 500.f, 400.f, 300.f, 400.f, 500.f, 600.f};

    int numPlataformas = (rand() % maxPlataformas) + 3;
    for (int i = 0; i < numPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(150.f + (i * 150.f), posicoesY[i]), false);
        listaEntidades.Incluir(pPlataforma);
        gerenciadorColisoes.IncluirObstaculo(pPlataforma);
    }
}

void Fase1::CriarCogumelosPulantes()
{
    int numCogumelos = (rand() % maxCogumelos) + 3;

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

    listaEntidades.Percorrer(); // Executa (Move/Desenha) Entidades
    gerenciadorColisoes.Executar(); // Checa colisões do frame atual
}

void Fase1::Salvar() {}