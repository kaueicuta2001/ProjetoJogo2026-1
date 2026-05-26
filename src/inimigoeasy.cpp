#include "inimigoeasy.h"
#include "gerenciadorgrafico.h"

using namespace sf;

InimigoEasy::InimigoEasy(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(50, 50);
    cor = Color::Red;
    num_vidas = 3;
    nivel_maldade = 1;
}

InimigoEasy::~InimigoEasy() {}

void InimigoEasy::Mover()
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
}

void InimigoEasy::Executar()
{
    Mover();
    pGG->DesenhaElemento(this);
}

void InimigoEasy::Salvar() {}
