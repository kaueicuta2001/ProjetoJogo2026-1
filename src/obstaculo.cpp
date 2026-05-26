#include "obstaculo.h"

Obstaculo::Obstaculo(int id, sf::Vector2f pos, bool danoso) : Entidade(id, pos), danoso(danoso) {}

Obstaculo::~Obstaculo() {}
