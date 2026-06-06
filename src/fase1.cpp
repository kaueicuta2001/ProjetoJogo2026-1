#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase1::Fase1(int id, Jogador* pJogador) :
Fase(id, pJogador),
maxBesouros(5),       
maxVespas(5),         
maxPlataformas(8),    
tamBG(pGG->getWindow()->getSize())
{
    // A ordem importa! Obstáculos desenhados primeiro, inimigos por cima
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
    // 5 Besouros patrulhando o chão, distribuídos ao longo da tela
    for (int i = 0; i < maxBesouros; i++)
    {
        // Eles nascem na altura 650 (perto do chão) e patrulham uma distância de 80px
        Besouro* pBesouro = new Besouro(i + 10, Vector2f(150.f + (i * 220.f), 650.f), 80.f);
        listaEntidades.Incluir(pBesouro);
        gerenciadorColisoes.IncluirInimigo(pBesouro);
    }
}

void Fase1::CriarVespas()
{
    // Arrays com as posições fixas das Vespas + 50 de Y (abaixando-as)
    float posicoesX[5] = {225.f, 375.f, 600.f, 825.f, 975.f};
    float posicoesY[5] = {500.f, 400.f, 250.f, 400.f, 500.f}; // Valores originais + 50

    for (int i = 0; i < maxVespas; i++)
    {
        // Amplitude de voo de 60px
        Vespa* pVespa = new Vespa(i + 30, Vector2f(posicoesX[i], posicoesY[i]), 60.f);
        listaEntidades.Incluir(pVespa);
        gerenciadorColisoes.IncluirInimigo(pVespa);
    }
}

void Fase1::CriarChao()
{
    int altura = Ente::pGG->getWindow()->getSize().y;
    int largura = Ente::pGG->getWindow()->getSize().x;
    Chao* pChao = new Chao(0, Vector2f(largura, altura));
    listaEntidades.Incluir(pChao);
    gerenciadorColisoes.IncluirObstaculo(pChao);
}

void Fase1::CriarPlataformas()
{
    // Level Design: Cria uma pirâmide perfeita para o Sapo escalar, abaixada em 50px
    float posicoesX[8] = {150.f, 300.f, 450.f, 600.f, 750.f, 900.f, 1050.f, 600.f};
    float posicoesY[8] = {600.f, 500.f, 400.f, 300.f, 400.f, 500.f, 600.f, 550.f}; // Valores originais + 50

    for (int i = 0; i < maxPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(posicoesX[i], posicoesY[i]), false);
        listaEntidades.Incluir(pPlataforma);
        gerenciadorColisoes.IncluirObstaculo(pPlataforma);
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
}

void Fase1::Executar()
{
    Desenhar(); // Desenha o Fundo primeiro

    listaEntidades.Percorrer(); // Executa (Move/Desenha) Entidades
    gerenciadorColisoes.Executar(); // Checa colisões do frame atual
}

void Fase1::Salvar() {}