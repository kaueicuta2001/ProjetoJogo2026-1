#include "entidade.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
posicao(pos),
tamanho(0.f, 0.f),
cor(sf::Color::White),
vivo(true)
{
}

Entidade::~Entidade()
{

}

void Entidade::setPosicao(sf::Vector2f pos)
{
    posicao = pos;
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

bool Entidade::getVivo()
{
    return vivo;
}

void Entidade::Desativar()
{
    vivo = false;
}
