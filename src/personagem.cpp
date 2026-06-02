#include "personagem.h"

Personagem::Personagem(int id, sf::Vector2f pos) :
Entidade(id, pos),
num_vidas(1),
vel(0.f, 0.f),
gravidade(0.5f),
noChao(false)
{

}

Personagem::~Personagem()
{

}

void Personagem::AplicarGravidade()
{
    if (!noChao)
    {
        vel.y += gravidade;
        if (vel.y > 15.f)
            vel.y = 15.f;
    }
    posicao.y += vel.y;
}

void Personagem::SetNoChao(bool chao)
{
    noChao = chao;
    if (chao)
        vel.y = 0.f;
}
