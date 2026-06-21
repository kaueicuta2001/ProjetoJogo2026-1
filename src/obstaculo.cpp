#include "obstaculo.h"
#include "jogador.h"

using namespace TheFrog::Entidades::Obstaculos;

Obstaculo::Obstaculo(int id, sf::Vector2f pos) :
Entidade(id, pos),
danoso(false),
colideInimigo(false)
{
    
}

Obstaculo::~Obstaculo()
{

}

bool Obstaculo::getDanoso() const
{
    return danoso;
}

bool Obstaculo::getColide() const
{
    return colideInimigo;
}
