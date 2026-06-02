#include "fase1.h"

 using namespace sf;
 using namespace std;

Fase1::Fase1(int id, Jogador* pJogador) : Fase(id, pJogador),
maxInimigosEasy(5), 
maxPlataformas(3)
{
    CriarInimigos();
    CriarObstaculos();
}

Fase1::~Fase1()
{
}

void Fase1::CriarInimigosEasy()
{
    for (int i = 0; i < maxInimigosEasy; i++)
    {
        InimigoEasy* pInimigoEasy = new InimigoEasy(i + 10, Vector2f(100 + i * 150, 100), 100.f);
        listaEntidades.Incluir(pInimigoEasy);
        gerenciadorColisoes.IncluirInimigo(pInimigoEasy);
    }
}

void Fase1::CriarPlataformas()
{
    for (int i = 0; i < maxPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(200 + i * 200, 150), false);
        listaEntidades.Incluir(pPlataforma);
        gerenciadorColisoes.IncluirObstaculo(pPlataforma);
    }
}

void Fase1::CriarInimigos()
{
    CriarInimigosEasy();
}

void Fase1::CriarObstaculos()
{
    CriarPlataformas();
}

void Fase1::Executar()
{
    listaEntidades.Percorrer();
    gerenciadorColisoes.VerificarColisoes(pJogador);
    gerenciadorColisoes.RemoverInimigoInativo();
    gerenciadorColisoes.RemoverObstaculoInativo();
}

void Fase1::Salvar() {}