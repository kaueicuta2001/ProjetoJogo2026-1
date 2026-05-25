#include "inimigoeasy.h"

using namespace std;
using namespace sf;

InimigoEasy::InimigoEasy(int id, Vector2f pos, int num_vidas, int nivel_maldade, float rraio) :
Inimigo(id, pos, num_vidas, nivel_maldade),
raio(rraio)
{
    tamanho = Vector2f(50, 50);
    cor = Color::Red;
}

InimigoEasy::~InimigoEasy()
{

}

void InimigoEasy::Mover()
{
    //cout << "Movendo...Inimigo facil" << endl;
}

void InimigoEasy::Executar()
{
    pGG->DesenhaElemento(this);
}

void InimigoEasy::Salvar()
{
    //cout << "Salvando..." << endl;
}