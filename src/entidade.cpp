#include "entidade.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
vivo(true),
gravidade(0.5f)
{
    posicao = pos;
    tamanho = Vector2f(0.f, 0.f);
}

Entidade::~Entidade()
{
    
}

void Entidade::setPosicao(sf::Vector2f pos)
{
    posicao = pos;
}

const sf::Vector2f Entidade::getPosicao()
{
    return posicao;
}

const sf::Vector2f Entidade::getTamanho()
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
    vel.y += gravidade;
    if (vel.y > 15.f)
        vel.y = 15.f;
    posicao.y += vel.y;
}

string Entidade::getNome()
{
    return nome;
}