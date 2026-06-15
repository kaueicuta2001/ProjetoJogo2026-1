#include "fase.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeEventos.h"
#include "inimigo.h"
#include "besouro.h"
#include "plataforma.h"
#include "obstdificil.h"
#include <iostream>

using namespace std;
using namespace sf;

Fase::Fase(int id, Jogador* jogador, Jogador* jogador2) :
Ente(id),
listaEntidades(),
gerenciadorColisoes(jogador, jogador2),
pJogador(jogador),
pJogador2(jogador2),
maxBesouros(5),
maxPlataformas(5),
maxObstDificil(5),
faseAtiva(true)
{
    relogioFase.restart(); 

    if (pJogador) {
        listaEntidades.Incluir(pJogador);
    }
    if (pJogador2) {
        listaEntidades.Incluir(pJogador2);
    }

    GerenciadorDeEventos::getGerenciadorDeEventos()->Anexar(this);
}

Fase::~Fase()
{
    GerenciadorDeEventos::getGerenciadorDeEventos()->Desanexar(this);
}

int Fase::getTempoJogado() const
{
    return static_cast<int>(relogioFase.getElapsedTime().asSeconds());
}

void Fase::Notificar(sf::Event evento)
{
    if(evento.type == Event::KeyPressed)
    {
        if(evento.key.code == Keyboard::Escape)
        {
            pGG->FecharJanela();
        }
    }
}

void Fase::CriarBesouros()
{
    int numBesouros = (rand() % (maxBesouros - 2)) + 3; 
    for (int i = 0; i < numBesouros; i++)
    {
        Besouro* pBesouro = new Besouro(i + 10, Vector2f(100.f + (i * 200.f), 100.f), 100.f);
        listaEntidades.Incluir(pBesouro);
        gerenciadorColisoes.IncluirInimigo(pBesouro);
    }
}

void Fase::CriarPlataformas()
{
    float posicoesY[5] = {600.f, 500.f, 400.f, 300.f, 400.f};

    int numPlataformas = (rand() % (maxPlataformas - 2)) + 3; 
    for (int i = 0; i < numPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(150.f + (i * 150.f), posicoesY[i]), false);
        listaEntidades.Incluir(pPlataforma);
        gerenciadorColisoes.IncluirObstaculo(pPlataforma);
    }
}

void Fase::CriarObstDificil()
{
    float posicoesX[5] = {250.f, 400.f, 550.f, 700.f, 850.f};
    float posicoesY[5] = {200.f, 300.f, 150.f, 350.f, 250.f};

    int numObstDificil = (rand() % (maxObstDificil - 2)) + 3; 
    for (int i = 0; i < numObstDificil; i++)
    {
        ObstDificil* pObstDificil = new ObstDificil(i + 100, Vector2f(posicoesX[i % 5], posicoesY[i % 5]), true, 50);
        listaEntidades.Incluir(pObstDificil);
        gerenciadorColisoes.IncluirObstaculo(pObstDificil);
    }
}

bool Fase::VerificarEstadoFase()
{
    if (pJogador && pJogador->getVidas() <= 0)
    {
        cout << "GAME OVER! Jogador 1 foi derrotado!" << endl;
        faseAtiva = false;
        return false;
    }
    
    if (pJogador2 && pJogador2->getVidas() <= 0)
    {
        cout << "GAME OVER! Jogador 2 foi derrotado!" << endl;
        faseAtiva = false;
        return false;
    }
    
    if (ContarInimigosVivos() <= 0)
    {
        cout << "VITORIA! Todos os inimigos foram derrotados!" << endl;
        faseAtiva = false;
        return false;
    }
    return true;
}

int Fase::ContarInimigosVivos()
{
    int countInimigos = 0;
    Lista<Entidade>::Elemento* atual = listaEntidades.getPrimeiro();
    
    while (atual != nullptr)
    {
        Entidade* pEnt = atual->getInfo();
        if (pEnt->getNome() == "Besouro" || pEnt->getNome() == "Vespa" || pEnt->getNome() == "Rei Besouro")
        {
            if (pEnt->getVivo()) {
                countInimigos++;
            }
        }
        atual = atual->getProximo();
    }
    return countInimigos;
}

void Fase::Executar()
{
    pGG->DesenharEnte(&sprite); 
    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
    VerificarEstadoFase();
}