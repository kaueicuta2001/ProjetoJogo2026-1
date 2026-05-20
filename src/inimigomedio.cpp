#include "inimigomedio.h"

using namespace std;

InimigoMedio::InimigoMedio(int tamanho, int nivel_maldade, int num_vidas, int x, int y, int id) :
Inimigo(nivel_maldade, num_vidas, x, y, id), tamanho(tamanho)
{
}

InimigoMedio::~InimigoMedio()
{
}

void InimigoMedio::Executar()
{
    cout << "Executando...Inimigo medio" << endl;
}

void InimigoMedio::Salvar()
{
    cout << "Salvando..." << endl;
    cout << "\n" << endl;
}
