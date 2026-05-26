#include "inimigo.h"

using namespace std;

Inimigo::Inimigo(int id, sf::Vector2f pos) :
Personagem(id, pos),
nivel_maldade(1)
{

}

Inimigo::~Inimigo()
{

}