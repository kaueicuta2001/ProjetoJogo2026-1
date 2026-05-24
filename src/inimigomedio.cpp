#include "inimigomedio.h"

using namespace std;

InimigoMedio::InimigoMedio(int id, sf::Vector2f pos, int tamanho, int nivel_maldade, int num_vidas) :
Inimigo(id, pos, num_vidas, nivel_maldade), tamanho(tamanho)
{
}

InimigoMedio::~InimigoMedio()
{
}

void InimigoMedio::Mover()
{
    //cout << "Movendo...Inimigo medio" << endl;
}

void InimigoMedio::Executar()
{
    //cout << "Executando...Inimigo medio" << endl;
}

void InimigoMedio::Salvar()
{
    //cout << "Salvando..." << endl;
    //cout << "\n" << endl;
}
