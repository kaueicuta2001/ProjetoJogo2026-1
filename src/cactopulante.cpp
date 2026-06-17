#include "cactopulante.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;

CactoPulante::CactoPulante(int id, sf::Vector2f pos, bool danoso, short int danosidade) : 
Obstaculo(id, pos, danoso), 
danosidade(danosidade),
espinhosFlamejantes(false)
{
    nome = "Cacto Pulante";
    tamanho = Vector2f(50.f, 50.f); 
    
    if (!textura.loadFromFile("../assets/cactopulante.png")) {
        cerr << "Aviso: textura cactopulante.png não encontrada!" << endl;
    }
    
    InicializarSprite(textura);
}

CactoPulante::~CactoPulante() {}

void CactoPulante::Obstaculizar(Jogador* pJogador)
{
    if (pJogador != nullptr && danoso)
    {
        pJogador->PerderVidas(danosidade);
        
        pJogador->setVelY(-15.f);
        pJogador->SetNoChao(false);

        if (!espinhosFlamejantes) {
            espinhosFlamejantes = true;
            danosidade *= 2; 
        }
    }
}

void CactoPulante::Executar() 
{
    AplicarGravidade();
    Gravitropismo();

    sprite.setPosition(posicao);
    Desenhar(); 
}

void CactoPulante::Salvar() {}