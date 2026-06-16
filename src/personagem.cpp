#include "personagem.h"

using namespace std;

Personagem::Personagem(int id, sf::Vector2f pos) :
Entidade(id, pos),
num_vidas(1),
noChao(false),
dano(0)
{

}

Personagem::~Personagem()
{

}

void Personagem::SetNoChao(bool chao)
{
    noChao = chao;
    if (chao)
        vel.y = 0.f;
}

bool Personagem::getNoChao()
{
    return noChao;
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