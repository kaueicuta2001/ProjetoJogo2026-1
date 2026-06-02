#include "chao.h"
#include "gerenciadorgrafico.h"

using namespace sf;

Chao::Chao(int id, sf::Vector2f windowSize) :
Obstaculo(id, Vector2f(0, windowSize.y - 20), false)
{
    tamanho = Vector2f(windowSize.x, 20.f);
    cor = Color::Green;
}

Chao::~Chao() {}

void Chao::Executar()
{
    pGG->DesenhaElemento(this);
}

void Chao::Salvar() {}
