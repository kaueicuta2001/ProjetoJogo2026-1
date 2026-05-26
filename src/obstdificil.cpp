#include "obstdificil.h"

ObstDificil::ObstDificil(int id, sf::Vector2f pos, bool danoso, short int danosidade) : Obstaculo(id, pos, danoso), danosidade(danosidade) {}

ObstDificil::~ObstDificil() {}

void ObstDificil::Executar() {}

void ObstDificil::Salvar() {}
