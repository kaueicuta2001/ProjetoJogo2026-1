#include "inimigo.h"
#include "jogador.h"

using namespace TheFrog::Entidades::Personagens;

Inimigo::Inimigo(int id, sf::Vector2f pos) :
Personagem(id, pos),
nivel_maldade(1),
colideObstaculo(true)
{

}

Inimigo::~Inimigo()
{

}

void Inimigo::salvarDataBuffer()
{
    
}

bool Inimigo::getColideObstaculo() const
{
    return colideObstaculo;
}