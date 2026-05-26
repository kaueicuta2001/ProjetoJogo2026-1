#include "inimigomedio.h"

InimigoMedio::InimigoMedio(int id, sf::Vector2f pos, int tamanho, int nivel_maldade, int num_vidas) : Inimigo(id, pos, num_vidas, nivel_maldade), tamanho(tamanho) {}

InimigoMedio::~InimigoMedio() {}

void InimigoMedio::Mover() {}

void InimigoMedio::Executar() {}

void InimigoMedio::Salvar() {}
