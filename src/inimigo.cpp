#include "inimigo.h"

Inimigo::Inimigo(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade) : Personagem(id, pos, num_vidas), nivel_maldade(nivel_maldade) {}

Inimigo::~Inimigo() {}
