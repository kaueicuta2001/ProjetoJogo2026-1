#include "inimigo.h"
#include "jogador.h"

Inimigo::Inimigo(int id, sf::Vector2f pos) :
Personagem(id, pos),
nivel_maldade(1),
colideObstaculo(true)
{

}

Inimigo::~Inimigo()
{

}

bool Inimigo::getColideObstaculo() const
{
    return colideObstaculo;
}