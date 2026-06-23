#include "ente.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace TheFrog;
using namespace Gerenciadores;

Ente::Ente(int id) :
id(id)
{}

Ente::Ente() :
id(-1)
{
    tamanho = static_cast<sf::Vector2f>(pGG->getWindow()->getSize());
    posicao = sf::Vector2f(0.f, 0.f);
}

Ente::~Ente() {}

GerenciadorGrafico* Ente::pGG = nullptr;

void Ente::setGG(GerenciadorGrafico* gg)
{
    pGG = gg;
}

int Ente::getId() const
{
    return id;
}

sf::Sprite& Ente::getSprite()
{
    return sprite; 
}

void Ente::InicializarSprite(sf::Texture& textura)
{
    sprite.setTexture(textura);
    sprite.setPosition(posicao);
    sf::Vector2u texSize = textura.getSize();
    if (texSize.x > 0 && texSize.y > 0)
    {
        sprite.setScale(
            tamanho.x / texSize.x,
            tamanho.y / texSize.y
        );
    }
}

void Ente::Desenhar()
{
    pGG->DesenharEnte(this);
}