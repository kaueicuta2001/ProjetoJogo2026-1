#include "obstmedio.h"

using namespace std;

ObstMedio::ObstMedio(float largura, bool danoso, int x, int y, int id) :
Obstaculo(danoso, x, y, id), largura(largura)
{
        cout << "objeto criado com sucesso....." << endl;
        cout << "A lagura do obstMedio eh de :" << largura << endl;
        (danoso) ? cout << "O obstaculo eh danosa" << endl : cout << "O obstaculomedio nop eh danosa" << endl;
        cout << "As coordenadas do obstaculomedio sao de :" << x << " para x, e :" << y << " para y" << endl;
        cout << "O id do objeto obstaculomedio eh: " << id << endl;
}

ObstMedio::~ObstMedio(){}

void ObstMedio::Executar()
{
    cout << "Executando...Obstaculo medio" << endl;
}

void ObstMedio::Salvar()
{
    cout << "Salvando..." << endl;
    cout << "\n" << endl;
}