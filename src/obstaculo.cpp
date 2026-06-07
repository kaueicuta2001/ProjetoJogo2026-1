#include "obstaculo.h"
#include "jogador.h"

Obstaculo::Obstaculo(int id, sf::Vector2f pos, bool danoso) :
Entidade(id, pos),
danoso(danoso)
{
    
}

Obstaculo::~Obstaculo()
{

}
