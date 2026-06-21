#include "entidade.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;
using namespace TheFrog::Entidades;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
vivo(true),
vel(0.f, 0.f),
gravidade(0.5f),
noChao(false)
{
    posicao = pos;
}

Entidade::~Entidade()
{
}

void Entidade::salvarDataBuffer()
{
}

void Entidade::setPosicao(sf::Vector2f pos)
{
    posicao = pos;
}

sf::Vector2f Entidade::getPosicao() const
{
    return posicao;
}

sf::Vector2f Entidade::getTamanho() const
{
    return tamanho;
}

bool Entidade::getVivo() const
{
    return vivo;
}

void Entidade::Desativar()
{
    vivo = false;
}

void Entidade::AplicarGravidade()
{
    if (!noChao)
    {
        vel.y += gravidade;
        if (vel.y > 15.f)
            vel.y = 15.f;
    }
    posicao.y += vel.y;
}

void Entidade::Gravitropismo()
{
    if (vel.y > 0.f)
        vel.y = 0.f;
    vel.y -= gravidade - 0.0000001f;
}

void Entidade::SetNoChao(bool chao)
{
    noChao = chao;
    if (chao)
        vel.y = 0.f;
}

bool Entidade::getNoChao() const
{
    return noChao;
}

string Entidade::getNome() const
{
    return nome;
}
