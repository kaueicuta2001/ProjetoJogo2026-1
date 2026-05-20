#include "inimigoeasy.h"

using namespace std;

InimigoEasy::InimigoEasy(float raio, int nivel_maldade, int num_vidas, int x, int y, int id) :
Inimigo(nivel_maldade, num_vidas, x, y, id), raio(raio)
{

}

InimigoEasy::~InimigoEasy()
{

}

void InimigoEasy::Executar()
{
    cout << "Executando...Inimigo facil" << endl;
}

void InimigoEasy::Salvar()
{
    cout << "Salvando..." << endl;
}