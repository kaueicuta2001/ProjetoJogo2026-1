#include "obstdificil.h"

using namespace std;

ObstDificil::ObstDificil(short int danosidade, bool danoso, int x, int y, int id) : Obstaculo(danoso, x, y, id), danosidade(danosidade)
{
    cout << "objeto criado com sucesso....." << endl;
    cout << "A taxa de danosidade é de :" << danosidade << endl;
    (danoso) ? cout << "O obstaculodificil eh danosa" << endl : cout << "O obstaculodificil nop eh danosa" << endl;
    cout << "As coordenadas do obstaculodificil sao de :" << x << " para x, e :" << y << " para y" << endl;
    cout << "O id do objeto obstaculodificil eh: " << id << endl;
}

ObstDificil::~ObstDificil()
{
}

void ObstDificil::Executar()
{
    cout << "Executando...Obstaculo Dificil" << endl;
}

void ObstDificil::Salvar()
{
    cout << "Salvando..." << endl;
}