#include "personagem.h"

Personagem::Personagem(int id, sf::Vector2f pos) : 
Entidade(id, pos), 
num_vidas(1),
vel(0.f, 0.f)
{
    
}

Personagem::~Personagem()
{

}
