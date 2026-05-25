#include "ente.h"

using namespace std;

Ente::Ente(int id) :
id(id)
{

}

Ente::~Ente()
{

}

GerenciadorGrafico* Ente::pGG = nullptr;

void Ente::setGG(GerenciadorGrafico* gg)
{
    pGG = gg;
}