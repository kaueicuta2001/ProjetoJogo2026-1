#include "bigchief.h"
#include "gerenciadorgrafico.h"

using namespace sf;

BigChief::BigChief(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
forca(100),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80, 80);
    cor = Color::Yellow;
    num_vidas = 5;
    nivel_maldade = 3;
}

BigChief::~BigChief() {}

void BigChief::Mover()
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

void BigChief::Executar()
{
    Mover();
    pGG->DesenhaElemento(this);
}

void BigChief::Salvar() {}
