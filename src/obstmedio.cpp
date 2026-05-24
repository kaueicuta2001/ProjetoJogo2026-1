#include "obstmedio.h"

using namespace std;

ObstMedio::ObstMedio(int id, sf::Vector2f pos, bool danoso, float largura) :
Obstaculo(id, pos, danoso),
largura(largura)
{
}

ObstMedio::~ObstMedio(){}

void ObstMedio::Executar()
{
    //cout << "Executando...Obstaculo medio" << endl;
}

void ObstMedio::Salvar()
{
    //cout << "Salvando..." << endl;
    //cout << "\n" << endl;
}