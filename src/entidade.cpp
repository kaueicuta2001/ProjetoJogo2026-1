#include "Entidade.h"

Entidade::Entidade(int id, sf::Vector2f pos) : Ente(id), posicao(pos), tamanho(0.f, 0.f), cor(sf::Color::White) {}
Entidade::~Entidade() {}
sf::Vector2f Entidade::getPosicao() const { return posicao; }
sf::Vector2f Entidade::getTamanho() const { return tamanho; }
sf::Color Entidade::getCor() const { return cor; }
void Entidade::setPosicao(sf::Vector2f pos) { posicao = pos; }