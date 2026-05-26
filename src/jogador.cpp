#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace sf;

Jogador::Jogador(int id, sf::Vector2f pos) :
Personagem(id, pos),
pontos(0)
{
    vel = Vector2f(5.f, 5.f);
    cor = Color::Green;
    tamanho = Vector2f(50.f, 50.f);
}

Jogador::~Jogador() {}

void Jogador::Mover()
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        posicao.x -= vel.x;
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        posicao.x += vel.x;
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        posicao.y -= vel.y;
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        posicao.y += vel.y;
    }
}

void Jogador::Executar()
{
    Ente::pGG->DesenhaElemento(this);
    Mover();
}

void Jogador::Salvar() {}
