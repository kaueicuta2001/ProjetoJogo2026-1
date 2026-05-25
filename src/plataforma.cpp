#include "plataforma.h"

using namespace std;

Plataforma::Plataforma(int id, sf::Vector2f pos, bool danoso, int altura) : 
Obstaculo(id, pos, danoso), 
altura(altura)
{
    tamanho = sf::Vector2f(100, 100);
    cor = sf::Color::Blue;
}

Plataforma::~Plataforma()
{

}

void Plataforma::Executar()
{
    pGG->DesenhaElemento(this);
}

void Plataforma::Salvar()
{
    //cout << "Salvando..." << endl;
}