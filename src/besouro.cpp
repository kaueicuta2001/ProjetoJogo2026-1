#include "besouro.h"
#include "jogador.h"

using namespace sf;
using namespace std;

Besouro::Besouro(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    nome = "Besouro";
    num_vidas = 10;
    dano = 10;
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(32.f, 32.f);
    num_vidas = 3;
    nivel_maldade = 1;
    if (!textura.loadFromFile("../assets/besouro.png"))
        cerr << "Erro ao carregar a textura do besouro!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida
}

Besouro::~Besouro() {}

void Besouro::Mover()
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

void Besouro::AprimorarMaldade()
{
    nivel_maldade++;
    dano += (nivel_maldade * 5); // Aumenta o dano a cada nível de maldade
}

void Besouro::Danificar(Jogador* jogador)
{
    if (jogador) {
        jogador->PerderVidas(dano);
        AprimorarMaldade();
    }
}

void Besouro::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    Desenhar();
}

void Besouro::Salvar() {}
