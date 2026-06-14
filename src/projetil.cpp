#include "projetil.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"

using namespace sf;
using namespace std;

Projetil::Projetil(int id, Vector2f pos, int direcao, int dano) :
Entidade(id, pos),
vel(Vector2f(4.f, 0.f)),
dano(dano),
direcao(direcao)
{
    nome = "Projetil";
    tamanho = Vector2f(16.f, 16.f);
    if (!textura.loadFromFile("../assets/projetil.png"))
        cerr << "Erro ao carregar a textura do projetil!" << endl;
    InicializarSprite(textura);
}

Projetil::~Projetil() {}

void Projetil::Mover()
{
    posicao.x += vel.x * direcao;

    float larguraJanela = static_cast<float>(pGG->getWindow()->getSize().x);
    if (posicao.x < -tamanho.x || posicao.x > larguraJanela)
    {
        Desativar();
    }
}

void Projetil::AumentarDano()
{
    dano = 15;
}

int Projetil::getDano() const
{
    return dano;
}

void Projetil::Danificar(Jogador* pJogador)
{
    if (pJogador != nullptr)
    {
        pJogador->PerderVidas(dano);
    }
    Desativar();
}

void Projetil::Executar()
{
    Mover();
    if (vivo)
    {
        sprite.setPosition(posicao);
        pGG->DesenharEnte(&sprite);
    }
}

void Projetil::Salvar() {}