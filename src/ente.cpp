#include "ente.h"
#include "gerenciadorgrafico.h"

using namespace sf;

Ente::Ente(int id) :
id(id),
textura(Texture()),
sprite(Sprite())
{}

Ente::~Ente() {}

GerenciadorGrafico* Ente::pGG = nullptr;

void Ente::setGG(GerenciadorGrafico* gg)
{
    pGG = gg;
}

void Ente::Desenhar()
{
    pGG->DesenharEnte(&sprite);
}