#include "inimigomedio.h"

using namespace std;

InimigoMedio::InimigoMedio(int id, sf::Vector2f pos) :
Inimigo(id, pos),
tamanho(50)
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
