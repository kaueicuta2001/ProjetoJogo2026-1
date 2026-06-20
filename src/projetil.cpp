#include "projetil.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"
#include "reibesouro.h"
#include <iostream>

using namespace sf;
using namespace std;

Projetil::Projetil(int id, Vector2f pos, ReiBesouro* rei) :
Entidade(id, pos),
pReiBesouro(rei)
{
    pReiBesouro = rei;
    dano = 5;
    direcaoTiro = rei ? rei->getDirecaoTiro() : Vector2f(1.f, 0.f); // Define a direção do tiro com base no Rei Besouro, ou para a direita por padrão
    nome = "Projetil";
    tamanho = Vector2f(20.0f, 20.0f);
    vel = Vector2f(2.5f, 2.5f); 

    if (!textura.loadFromFile("../assets/projetilbesouro.png"))
        cerr << "Erro ao carregar a textura do projetil!" << endl;
        
    InicializarSprite(textura);
}

Projetil::~Projetil() {
    if(pReiBesouro)
        pReiBesouro->setProjetil(nullptr); // Limpa a referência ao projétil no Rei Besouro
}

void Projetil::Mover()
{
    // Move o projétil na direção diagonal salva no momento do disparo
    posicao.x += vel.x * direcaoTiro.x;
    posicao.y += vel.y * direcaoTiro.y;

    // Morre se encostar nas arestas laterais (x = 0 ou largura máxima)
    float larguraJanela = static_cast<float>(pGG->getWindow()->getSize().x);
    float alturaJanela = static_cast<float>(pGG->getWindow()->getSize().y);
    if (posicao.x <= 0.f || posicao.x >= larguraJanela || posicao.y <= 0.f || posicao.y >= alturaJanela)
    {
        Desativar();
    }
}

void Projetil::AumentarDano()
{
    if(pReiBesouro) {
        dano = (10 + (pReiBesouro->getDano() / 2));
    }

    else {
       cerr << "Erro: Rei Besouro não encontrado para aumentar o dano do projétil!" << endl;
    }
}
void Projetil::Danificar(Jogador* pJogador)
{
    if (pJogador)
    {
        pJogador->PerderVidas(dano);
        pReiBesouro->ResetAtirar(); // Reseta o estado de atirar do Rei Besouro para evitar múltiplos projéteis
        pReiBesouro->AprimorarMaldade();
        Desativar();
    }
}

void Projetil::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    Desenhar();
}

void Projetil::Salvar() {}