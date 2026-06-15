#include "projetil.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"
#include <iostream>

using namespace sf;
using namespace std;

Projetil::Projetil(int id, Vector2f pos, Vector2f dirNormalizada, int dano) :
Entidade(id, pos),
vel(Vector2f(3.75f, 3.75f)), // Três quartos da velocidade do jogador (3/4 de 5.f)
dano(dano),
direcaoTiro(dirNormalizada)
{
    nome = "Projetil";
    tamanho = Vector2f(26.6f, 26.6f); // Um terço do tamanho do Rei Besouro (80.f / 3)
    
    if (!textura.loadFromFile("../assets/projetilbesouro.png"))
        cerr << "Erro ao carregar a textura do projetil!" << endl;
        
    InicializarSprite(textura);
}

Projetil::~Projetil() {}

void Projetil::Mover()
{
    // Move o projétil na direção diagonal salva no momento do disparo
    posicao.x += vel.x * direcaoTiro.x;
    posicao.y += vel.y * direcaoTiro.y;

    // Morre se encostar nas arestas laterais (x = 0 ou largura máxima)
    float larguraJanela = static_cast<float>(pGG->getWindow()->getSize().x);
    if (posicao.x <= 0.f || posicao.x >= larguraJanela)
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
    if (pJogador)
    {
        pJogador->PerderVidas(dano);
    }
}

void Projetil::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite); 
}

void Projetil::Salvar() {}