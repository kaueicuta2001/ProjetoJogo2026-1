#include "cactopulante.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;

CactoPulante::CactoPulante(int id, sf::Vector2f pos) : 
Obstaculo(id, pos),
danosidade(10),
espinhosFlamejantes(false)
{
    nome = "Cacto Pulante";
    tamanho = Vector2f(48.f, 64.f);
    danoso = true; 
    
    if (!textura.loadFromFile("../assets/cactopulante.png")) {
        cerr << "Aviso: textura cactopulante.png não encontrada!" << endl;
    }
    
    InicializarSprite(textura);
}

CactoPulante::~CactoPulante() {}

void CactoPulante::FlamejarEspinhos() {
    if (!textura.loadFromFile("../assets/cactoflamejante.png")) {
        cerr << "Aviso: textura cactoflamejante.png não encontrada!" << endl;
        InicializarSprite(textura);
    }
    danosidade *= 2;

}

void CactoPulante::Obstaculizar(Jogador* pJogador)
{
    if (pJogador != nullptr && danoso)
    {
        pJogador->PerderVidas(danosidade);
        
        pJogador->setVelY(-15.f);
        pJogador->SetNoChao(false);

        if (!espinhosFlamejantes) {
            espinhosFlamejantes = true;
            FlamejarEspinhos(); 
        }
    }
}

void CactoPulante::Executar() 
{
    Gravitropismo();
    AplicarGravidade();

    sprite.setPosition(posicao);
    Desenhar(); 
}

void CactoPulante::Salvar() {}