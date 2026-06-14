#include "entidade.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
vivo(true)
{
    posicao = pos;
    tamanho = Vector2f(0.f, 0.f);
}

Entidade::~Entidade()
{
    
}

void Entidade::setPosicao(sf::Vector2f pos)
{
    posicao = pos;
}

const sf::Vector2f Entidade::getPosicao()
{
    return posicao;
}

const sf::Vector2f Entidade::getTamanho()
{
    return tamanho;
}

bool Entidade::getVivo() const
{
    return vivo;
}

void Entidade::Desativar()
{
    vivo = false;
}

void Entidade::InicializarSprite(sf::Texture& textura)
{
    sprite.setTexture(textura);
     
// Faz a conta de escala UMA ÚNICA VEZ aqui no início
    sf::Vector2u texSize = textura.getSize();
    if (texSize.x > 0 && texSize.y > 0)
    {
        sprite.setScale(
            tamanho.x / texSize.x,
            tamanho.y / texSize.y
        );
    }
}
