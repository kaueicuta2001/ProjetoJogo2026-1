#include "plataforma.h"

using namespace std;

Plataforma::Plataforma(int altura, bool danoso, int x, int y, int id) : 
Obstaculo(danoso, x, y, id), altura(altura)
{   
    cout << "objeto criado com sucesso....." << endl;
    cout << "A plataforma tem a altura de:" << altura << endl;
    (danoso) ? cout << "A plataforma eh danosa" << endl : cout << "A plataforma nop eh danosa" << endl;
    cout << "As coordenadas da plataforma sao de :" << x << " para x, e :" << y << " para y" << endl;
    cout << "O id do objeto plataforma eh: " << id << endl;
}

Plataforma::~Plataforma()
{

}

void Plataforma::Executar()
{
    cout << "Executando...Plataforma" << endl;
}

void Plataforma::Salvar()
{
    cout << "Salvando..." << endl;
}