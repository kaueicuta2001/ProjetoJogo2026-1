#include "fase2.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;
using namespace TheFrog::Fases;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Listas;
using namespace TheFrog::Entidades;
using namespace TheFrog::Entidades::Obstaculos;
using namespace TheFrog::Entidades::Personagens;

Fase2::Fase2(int id, Jogador* pJogador = nullptr, Jogador* pJogador2 = nullptr) :
Fase(id, pJogador, pJogador2),
maxVespas(5),         
maxReiBesouro(5)
{
    if (!textura.loadFromFile("../assets/fase2BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    CriarCenario();
    CriarObstaculos();
    CriarInimigos();
}

Fase2::~Fase2()
{
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

void Fase2::CriarCactosPulantes()
{
    int numCactos = (rand() % (maxObstDificil - 2)) + 3;

    float posicoesX[5] = {250.f, 550.f, 850.f, 400.f, 700.f};
    float altura = tamanho.y - 32.f - 64.f;

    for (int i = 0; i < numCactos; i++)
    {
        CactoPulante* pCacto = new CactoPulante(i + 50, Vector2f(posicoesX[i], altura));
        listaEntidades.Incluir(pCacto);
        gerenciadorColisoes.IncluirObstaculo(pCacto);
    }
}

void Fase2::CriarInimigos()
{
    CriarBesouros();
    CriarReiBesouro();
}

void Fase2::CriarObstaculos()
{
    CriarPlataformas();
    CriarCactosPulantes();
}

void Fase2::VerificarAtirarReiBesouro()
{
    for(ReiBesouro* rei : vReiBesouros)
    {
        if (rei->getAtirar())
        {
            Projetil* pProjetil = new Projetil(100 + rei->getId(), rei->getPosicao(), rei);
            rei->setProjetil(pProjetil);
            listaEntidades.Incluir(pProjetil);
            gerenciadorColisoes.IncluirProjetil(pProjetil);
            
            rei->ResetAtirar(); 
        }
    }
}

void Fase2::Executar()
{
    Desenhar();
    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
    VerificarAtirarReiBesouro();
    Fase::Executar();
}