#include "fase1.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Fase1::Fase1(int id, Jogador* pJogador) :
Fase(id, pJogador),
maxInimigosEasy(5), 
maxPlataformas(3),
tamBG(pGG->getWindow()->getSize())
{
    CriarInimigos();
    CriarObstaculos();
    InicializarBG();
}

Fase1::~Fase1()
{
    pJogador = nullptr;
    listaEntidades.Esvaziar();
}

void Fase1::InicializarBG()
{
    if (!textura.loadFromFile("../assets/fase1BG.png"))
       cerr << "Erro ao carregar a textura de fundo!" << endl;
    sprite.setTexture(textura);
    sprite.setPosition(0.f, 0.f);
    sprite.setScale(
        tamBG.x / textura.getSize().x,
        tamBG.y / textura.getSize().y
    );
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

void Fase1::CriarChao()
{
    int altura = Ente::pGG->getWindow()->getSize().y;
    int largura = Ente::pGG->getWindow()->getSize().x;
    Chao* pChao = new Chao(0, Vector2f(largura, altura));
    listaEntidades.Incluir(pChao);
    gerenciadorColisoes.IncluirObstaculo(pChao);
}

void Fase1::CriarPlataformas()
{
    for (int i = 0; i < maxPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(200 + i * 200, 400), false);
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
    CriarChao();
}

void Fase1::Executar()
{
    Desenhar();

    listaEntidades.Percorrer();
    gerenciadorColisoes.Executar();
}

void Fase1::Salvar() {}