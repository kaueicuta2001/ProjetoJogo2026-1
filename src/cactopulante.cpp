#include "cactopulante.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;
using namespace TheFrog::Entidades::Obstaculos;

CactoPulante::CactoPulante(int id, sf::Vector2f pos) : 
Obstaculo(id, pos),
danosidade(10),
espinhosFlamejantes(false)
{
    nome = "Cacto Pulante";
    tamanho = Vector2f(48.f, 64.f);
    danoso = true; 
    vidaJogador = 100;
    
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

void CactoPulante::Obstaculizar(Personagens::Jogador* pJogador)
{
    if (pJogador)
    {  
        Danificar(pJogador);     
        pJogador->setVelY(-15.f);
        pJogador->SetNoChao(false);

        if (!espinhosFlamejantes) {
            espinhosFlamejantes = true;
            FlamejarEspinhos(); 
        }
    }
}

void CactoPulante::Danificar(Personagens::Jogador* pJogador) {
    if (pJogador) {
        if(!pJogador->getImune()) {
            pJogador->PerderVidas(danosidade);
            pJogador->IniciarImunidade();
        }
    }
        vidaJogador = pJogador->getVidas();
}

void CactoPulante::Executar() 
{
    Gravitropismo();
    AplicarGravidade();

    if (vidaJogador <= 50) {
        danosidade = 20;
    }

    sprite.setPosition(posicao);
    Desenhar(); 
}

void CactoPulante::Salvar() {}