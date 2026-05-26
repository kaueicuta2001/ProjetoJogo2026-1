#include "plataforma.h"
#include "gerenciadorgrafico.h"

using namespace sf;

Plataforma::Plataforma(int id, sf::Vector2f pos, bool danoso) : 
Obstaculo(id, pos, danoso), 
tempo(100)
{
    tamanho = sf::Vector2f(100.f, 20.f);
    cor = sf::Color::Blue;
}

Plataforma::~Plataforma() {}

/* void Plataforma::obstaculizar()
{
    
} */

void Plataforma::Executar()
{
    pGG->DesenhaElemento(this);
    if(tempo > 0)
        tempo--;
    else
        Desativar();
}

void Plataforma::Salvar() {}
