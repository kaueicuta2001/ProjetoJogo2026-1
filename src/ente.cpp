#include "ente.h"
#include "gerenciadorgrafico.h"

using namespace sf;

Ente::Ente(int id) :
id(id),
textura(Texture()),
sprite(Sprite())
{}

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
sf::Sprite& Ente::getSprite() { return sprite; }

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