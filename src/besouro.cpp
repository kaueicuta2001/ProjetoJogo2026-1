#include "besouro.h"
#include "gerenciadorgrafico.h"
#include "jogador.h" // Necessário para o Besouro conseguir ferir o Jogador

using namespace sf;
using namespace std;

Besouro::Besouro(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1),
antenasVenenosas(false)
{
    nome = "Besouro";
    num_vidas = 20;
    dano = 5; // O dano que o Besouro causa ao encostar no Sapo
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(40.f, 40.f);
    nivel_maldade = 1;
    
    if (!textura.loadFromFile("../assets/besouro.png"))
        cerr << "Erro ao carregar a textura do besouro!" << endl;
    InicializarSprite(textura);
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

    if(!noChao)
        AplicarGravidade();
}

void Besouro::AtivarAntenaVenenosa()
{
    antenasVenenosas = true;
    AprimorarMaldade();
}

void Besouro::AprimorarMaldade()
{
    dano *= 2;
    AlterarSpriteMeiaVida();
}

void Besouro::AlterarSpriteMeiaVida()
{
    if (!textura.loadFromFile("../assets/besouromeiavida.png"))
        cerr << "Erro ao carregar a textura do besouro meia vida!" << endl;
    sprite.setTexture(textura);
}

void Besouro::Executar()
{
    if (num_vidas <= 10 && !antenasVenenosas)
    {
        AtivarAntenaVenenosa();
    }
    
    Mover();
    sprite.setPosition(posicao);
    Desenhar();
}

// Lógica de dar dano ao Sapo se ele encostar no Besouro (pela lateral)
void Besouro::Danificar(Jogador* pJogador)
{
    if(pJogador != nullptr)
    {
        pJogador->PerderVidas(dano);
    }
}

void Besouro::Salvar() {}