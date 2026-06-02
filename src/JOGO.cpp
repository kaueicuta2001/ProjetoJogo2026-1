#include "jogo.h"

using namespace sf;

Jogo::Jogo() : GG(GerenciadorGrafico::getGerenciadorGrafico()), pJogador(nullptr)
{
    pJogador = new Jogador(5, Vector2f(50.f, 50.f));
    faseAtual = new Fase1(1, pJogador);
    Ente::setGG(GG);
    Executar();
}

Jogo::~Jogo() {
    delete pJogador;
    delete faseAtual;
}

void Jogo::InstanciarEntidades() {}

void Jogo::Executar()
{
    while (GG->VerificaJanelaAberta())
    {
        Event event;

        while (GG->getWindow()->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                GG->FecharJanela();
            }
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    GG->FecharJanela();
                }
            }
        }

        GG->LimpaJanela();
        pJogador->Executar();
        faseAtual->Executar();
        GG->Renderizar();
    }
}
