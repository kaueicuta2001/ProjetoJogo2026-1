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
    Plataforma* pPlataforma = new Plataforma(2, Vector2f(0, 400), false);
    Chao* pChao = new Chao(3, Vector2f(800, 600));
    InimigoEasy* pInimigoEasy = new InimigoEasy(1, Vector2f(500, 300), 100.f);
    InimigoMedio* pInimigoMedio = new InimigoMedio(4, Vector2f(200, 250), 80.f);
    BigChief* pBigChief = new BigChief(5, Vector2f(650, 200), 120.f);

    listaInimigos.Incluir(pInimigoEasy);
    listaInimigos.Incluir(pInimigoMedio);
    listaInimigos.Incluir(pBigChief);

    listaObstaculos.Incluir(pPlataforma);
    listaObstaculos.Incluir(pChao);

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
