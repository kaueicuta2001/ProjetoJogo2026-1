#include "inimigo.h"

Inimigo::Inimigo(int nivel_maldade, int num_vidas, int x, int y, int id) : Personagem(num_vidas, x, y, id), nivel_maldade(nivel_maldade)
{

}

Inimigo::~Inimigo()
{

}