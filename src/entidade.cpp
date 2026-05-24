#include "entidade.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
posicao(pos),
tamanho(0.f, 0.f),
cor(sf::Color::White)
{
}

Entidade::~Entidade()
{

}

sf::Vector2f Entidade::getPosicao()
{
    return posicao;
}

sf::Vector2f Entidade::getTamanho()
{
    return tamanho;
}

sf::Color Entidade::getCor()
{
    return cor;
}