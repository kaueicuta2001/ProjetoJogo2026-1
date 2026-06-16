#include "entidade.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Entidade::Entidade(int id, sf::Vector2f pos) :
Ente(id),
vivo(true),
vel(0.f, 0.f),
gravidade(0.5f),
noChao(false)
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

sf::Vector2f Entidade::getPosicao() const
{
    return posicao;
}

sf::Vector2f Entidade::getTamanho() const
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
     
    sf::Vector2u texSize = textura.getSize();
    if (texSize.x > 0 && texSize.y > 0)
    {
        sprite.setScale(
            tamanho.x / texSize.x,
            tamanho.y / texSize.y
        );
    }
}

void Entidade::AplicarGravidade()
{
    if (!noChao)
    {
        vel.y += gravidade;
        if (vel.y > 15.f)
            vel.y = 15.f;
    }
    posicao.y += vel.y;
}

void Entidade::Gravitropismo()
{
    vel.y -= gravidade; 
}

void Entidade::SetNoChao(bool chao)
{
    noChao = chao;
    if (chao)
        vel.y = 0.f;
}

bool Entidade::getNoChao() const
{
    return noChao;
}

void Entidade::setVelY(float vY)
{
    vel.y = vY;
}

void Entidade::setVelX(float vX)
{
    vel.x = vX;
}

float Entidade::getVelY() const
{
    return vel.y;
}

string Entidade::getNome() const
{
    return nome;
}