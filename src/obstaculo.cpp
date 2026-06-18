#include "obstaculo.h"
#include "jogador.h"

Obstaculo::Obstaculo(int id, sf::Vector2f pos) :
Entidade(id, pos),
danoso(false)
{
    
}

Obstaculo::~Obstaculo()
{

}
