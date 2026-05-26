#include "jogo.h"

using namespace sf;

Jogo::Jogo() : GG(GerenciadorGrafico::getGerenciadorGrafico()), pJogador(nullptr)
{
    Ente::setGG(GG);
    Executar();
}

Jogo::~Jogo() {}

void Jogo::InstanciarEntidades()
{
    pJogador = new Jogador(0, Vector2f(100, 100));
    Plataforma* pPlataforma = new Plataforma(2, Vector2f(300, 150), false);
    InimigoEasy* pInimigoEasy = new InimigoEasy(1, Vector2f(500, 100), 100.f);

    listaInimigos.Incluir(pInimigoEasy);
    listaObstaculos.Incluir(pPlataforma);

    gerenciadorColisoes.setListas(&listaInimigos, &listaObstaculos);
}

void Jogo::Executar()
{
    InstanciarEntidades();

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
        listaInimigos.Percorrer();
        listaObstaculos.Percorrer();
        gerenciadorColisoes.VerificarColisoes(pJogador);
        GG->Renderizar();
    }
}
