#include "obstdificil.h"

using namespace std;

ObstDificil::ObstDificil(int id, sf::Vector2f pos, bool danoso, short int danosidade) : 
Obstaculo(id, pos, danoso),
danosidade(danosidade)
{
}

ObstDificil::~ObstDificil()
{
}

void ObstDificil::Executar()
{
    //cout << "Executando...Obstaculo Dificil" << endl;
}

void ObstDificil::Salvar()
{
    //cout << "Salvando..." << endl;
}