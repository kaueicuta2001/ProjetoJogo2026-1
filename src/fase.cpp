#include "fase.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Fase::Fase(int id, Jogador* jogador, Jogador* jogador2) :
Ente(id),
maxBesouros(5),
maxPlataformas(5),
pJogador(jogador),
pJogador2(jogador2),
gerenciadorColisoes(jogador, jogador2)
{
}

Fase::~Fase()
{
}

void Fase::TratarEventos()
{
    Event event;

    while (pGG->getWindow()->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            pGG->FecharJanela();
        }

        if(event.type == Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Escape)
            {
                pGG->FecharJanela();
            }
        }
    }
}

void Fase::CriarBesouros()
{
    int numBesouros = (rand() % (maxBesouros - 2)) + 3; // Gera um número aleatório entre 3 e maxBesouros
    for (int i = 0; i < numBesouros; i++)
    {
        Besouro* pBesouro = new Besouro(i + 10, Vector2f(150.f + (i * 220.f), 650.f), 80.f);
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

void Fase::CriarChao()
{
    Chao* pChao = new Chao(0, Vector2f(0.f, Ente::pGG->getWindow()->getSize().y - 32.f), false);
    listaEntidades.Incluir(pChao);
    gerenciadorColisoes.IncluirObstaculo(pChao);
}

void Fase::CriarCenario()
{
    sprite.setTexture(textura);
    sprite.setPosition(0.f, 0.f);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );
}