#include "personagem.h"

using namespace std;
using namespace sf;

Personagem::Personagem(int id, sf::Vector2f pos, int num_vidas) : 
Entidade(id, pos), 
num_vidas(num_vidas),
vel(0.f, 0.f)
{
    
}

Personagem::~Personagem()
{

}