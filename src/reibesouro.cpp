#include "reibesouro.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeColisoes.h"
#include "listaentidades.h"
#include "projetil.h"
#include "jogador.h"

using namespace sf;
using namespace std;

ReiBesouro::ReiBesouro(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
forca(100),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1),
carapaçaEndurecida(false),
tempoTiro(120),
maxTempoTiro(120),
pGerenciadorColisoes(nullptr),
pListaEntidades(nullptr)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80, 80);
    num_vidas = 100;
    nivel_maldade = 3;
    dano = 10;
    nome = "Rei Besouro";
    if (!textura.loadFromFile("../assets/reibesouro.png"))
        std::cerr << "Erro ao carregar a textura do Rei Besouro!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida

}

ReiBesouro::~ReiBesouro() {}

void ReiBesouro::setGerenciadorColisoes(GerenciadorDeColisoes* pGC)
{
    pGerenciadorColisoes = pGC;
}

void ReiBesouro::setListaEntidades(ListaEntidades* pLE)
{
    pListaEntidades = pLE;
}

void ReiBesouro::Mover()
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

void ReiBesouro::AprimorarMaldade()
{
    dano *= 2;
    AlterarSpriteMeiaVida();
}

void ReiBesouro::AlterarSpriteMeiaVida()
{
    if (!textura.loadFromFile("../assets/reibesouromeiavida.png"))
        cerr << "Erro ao carregar a textura do rei besouro meia vida!" << endl;
    sprite.setTexture(textura);
}

void ReiBesouro::Atirar()
{
    if (!pGerenciadorColisoes || !pListaEntidades) return;

    Vector2f posProjetil = Vector2f(
        posicao.x + (direcao > 0 ? tamanho.x : -16.f),
        posicao.y + tamanho.y / 2.f - 8.f
    );

    Projetil* pProjetil = new Projetil(id * 1000 + tempoTiro, posProjetil, direcao, 5);

    if (carapaçaEndurecida)
    {
        pProjetil->AumentarDano();
    }

    pListaEntidades->Incluir(pProjetil);
    pGerenciadorColisoes->IncluirProjetil(pProjetil);
}

void ReiBesouro::Executar()
{
    if (num_vidas <= 50 && !carapaçaEndurecida)
    {
        EndurecerCarapaça();
    }

    if (tempoTiro > 0)
    {
        tempoTiro--;
    }
    else
    {
        Atirar();
        tempoTiro = maxTempoTiro;
    }

    Mover();
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void ReiBesouro::EndurecerCarapaça()
{
    carapaçaEndurecida = true;
    AprimorarMaldade();
}

void ReiBesouro::Danificar(Jogador* pJogador)
{
    if(pJogador != nullptr)
    {
        pJogador->PerderVidas(dano);
    }
}

void ReiBesouro::Salvar() {}