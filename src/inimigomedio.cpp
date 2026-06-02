#include "inimigomedio.h"
#include "gerenciadorgrafico.h"

using namespace sf;

InimigoMedio::InimigoMedio(int id, sf::Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    vel = Vector2f(1.5f, 0.f);
    tamanho = Vector2f(60, 60);
    cor = Color::Magenta;
    num_vidas = 2;
    nivel_maldade = 2;
}

InimigoMedio::~InimigoMedio() {}

void InimigoMedio::Mover()
{
    posicao.x += vel.x * direcao;

    if (posicao.x > limiteDir)
    {
        direcao = -1;
    }
    else if (posicao.x < limiteEsq)
    {
        direcao = 1;
    }

    AplicarGravidade();
}

void InimigoMedio::Executar()
{
    Mover();
    pGG->DesenhaElemento(this);
}

void InimigoMedio::Salvar() {}
