#include "inimigoeasy.h"
#include "gerenciadorgrafico.h"

using namespace sf;

InimigoEasy::InimigoEasy(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade, float rraio) : Inimigo(id, pos, num_vidas, nivel_maldade), raio(rraio)
{
    tamanho = Vector2f(50, 50);
    cor = Color::Red;
}

InimigoEasy::~InimigoEasy() {}

void InimigoEasy::Mover() {}

void InimigoEasy::Executar()
{
    pGG->DesenhaElemento(this);
}

void InimigoEasy::Salvar() {}
