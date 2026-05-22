#include "entidade.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
posicao(pos),
tamanho(0.f, 0.f),
cor(sf::Color::White)
{
    corpo.setSize(tamanho);
    corpo.setFillColor(cor);
    corpo.setPosition(posicao);
}

Entidade::~Entidade()
{

}