#include "personagem.h"

using namespace std;

Personagem::Personagem(int id, sf::Vector2f pos) :
Entidade(id, pos),
num_vidas(1),
vel(0.f, 0.f),
gravidade(0.5f),
noChao(false),
dano(0)
{

}

Personagem::~Personagem()
{

}

void Personagem::AplicarGravidade()
{
    if (!noChao)
    {
        vel.y += gravidade;
        if (vel.y > 15.f)
            vel.y = 15.f;
    }
    posicao.y += vel.y;
}

void Personagem::SetNoChao(bool chao)
{
    noChao = chao;
    if (chao)
        vel.y = 0.f;
}

void Personagem::PerderVidas(int danos)
{
    num_vidas -= danos;
    cout << nome << " perdeu " << danos << " vidas. Vidas restantes: " << num_vidas << endl;
    if (num_vidas <= 0){
        num_vidas = 0;
        Desativar();
    }
}

int Personagem::getVidas() const
{
    return num_vidas;
}

int Personagem::getDano() const
{
    return dano;
}