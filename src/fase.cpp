#include "fase.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Fase::Fase(int id, Jogador* jogador) :
Ente(id),
pJogador(jogador),
gerenciadorColisoes(jogador)
{
}

Fase::~Fase()
{
}

void Fase::TratarEventos()
{
    Event event;

    while (pGG->getWindow()->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            pGG->FecharJanela();
        }

        if(event.type == Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Escape)
            {
                pGG->FecharJanela();
            }
        }
    }
}