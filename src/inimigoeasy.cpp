#include "inimigoeasy.h"
#include "jogador.h"

using namespace sf;
using namespace std;

InimigoEasy::InimigoEasy(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    nome = "InimigoEasy";
    num_vidas = 10;
    dano = 10;
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(32.f, 32.f);
    num_vidas = 3;
    nivel_maldade = 1;
    if (!textura.loadFromFile("../assets/besouro.png"))
        cerr << "Erro ao carregar a textura do inimigo fácil!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida
}

InimigoEasy::~InimigoEasy() {}

void InimigoEasy::Mover()
{
    posicao.x += vel.x * direcao;

    if (posicao.x > limiteDir)
    {
        direcao = -1;
    }
    else if (posicao.x < limiteEsq)
    {
        direcao = 1;
    }

    AplicarGravidade();
}

void InimigoEasy::AprimorarMaldade()
{
    nivel_maldade++;
    dano += (nivel_maldade * 5); // Aumenta o dano a cada nível de maldade
}

void InimigoEasy::Danificar(Jogador* jogador)
{
    if (jogador) {
        jogador->PerderVidas(dano);
        AprimorarMaldade();
    }
}

void InimigoEasy::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    Desenhar();
}

void InimigoEasy::Salvar() {}
