#include "jogo.h"

using namespace sf;

Jogo::Jogo() : GG(GerenciadorGrafico::getGerenciadorGrafico()), pJogador(nullptr)
{
    Ente::setGG(GG);
    pJogador = new Jogador(5, Vector2f(50.f, 50.f));
    faseAtual = new Fase1(1, pJogador);
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

        // Usando o método getVidas() que já está implementado na tua classe!
        if (pJogador->getVidas() <= 0)
        {
            GG->FecharJanela();
        }

        GG->LimpaJanela();
        faseAtual->Executar();
        pJogador->Executar();
        GG->Renderizar();
    }
}