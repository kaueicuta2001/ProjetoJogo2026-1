#include "bigchief.h"

BigChief::BigChief(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade, short int poder) : Inimigo(id, pos, num_vidas, nivel_maldade), forca(poder) {}

BigChief::~BigChief() {}

void BigChief::Mover() {}

void BigChief::Executar() {}

void BigChief::Salvar() {}
