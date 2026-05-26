#include "ente.h"
#include "gerenciadorgrafico.h"

Ente::Ente(int id) : id(id) {}

Ente::~Ente() {}

void Ente::setGG(GerenciadorGrafico* gg)
{
    pGG = gg;
}

GerenciadorGrafico* Ente::pGG = nullptr;
