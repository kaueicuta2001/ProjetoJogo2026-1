#include "obstmedio.h"

ObstMedio::ObstMedio(int id, sf::Vector2f pos, bool danoso, float largura) : Obstaculo(id, pos, danoso), largura(largura) {}

ObstMedio::~ObstMedio() {}

void ObstMedio::Executar() {}

void ObstMedio::Salvar() {}
