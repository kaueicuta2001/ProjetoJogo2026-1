#include "jogador.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;

Jogador::Jogador(int id, sf::Vector2f pos, bool isJogador2) :
Personagem(id, pos),
pontos(0),
imune(false),
tempoImune(0),
maxTempoImune(180),
jogador2(isJogador2)
{
    nome = "Jogador";
    num_vidas = 100;
    dano = 10;
    vel = Vector2f(5.f, 5.f);
    tamanho = Vector2f(40.f, 40.f);
    
    if(!textura.loadFromFile(jogador2 ? "../assets/jogador2.png" : "../assets/jogador1.png"))
        cerr << "Erro ao carregar a textura do jogador!" << endl;
        
    InicializarSprite(textura);
}

Jogador::~Jogador() {}

void Jogador::Mover()
{
   
    if(!jogador2){
        if (Keyboard::isKeyPressed(Keyboard::A)) posicao.x -= vel.x;
        if (Keyboard::isKeyPressed(Keyboard::D)) posicao.x += vel.x;
        if (Keyboard::isKeyPressed(Keyboard::W) && noChao) Pular();
    } else {
        if (Keyboard::isKeyPressed(Keyboard::Left)) posicao.x -= vel.x;
        if (Keyboard::isKeyPressed(Keyboard::Right)) posicao.x += vel.x;
        if (Keyboard::isKeyPressed(Keyboard::Up) && noChao) Pular();
    }
    AplicarGravidade();
}

void Jogador::Pular() {
    vel.y = -10.f;
    noChao = false;
}

void Jogador::setVelY(float velY) {
    vel.y = velY;
}

void Jogador::Pisar(Inimigo* inimigo) {
    if (inimigo) {
        inimigo->PerderVidas(dano);
        pontos += dano;
    }
    Pular();
}

int Jogador::getVidas() const {
    return num_vidas;
}

bool Jogador::getImune() const {
    return imune;
}

void Jogador::IniciarImunidade() {
    imune = true;
    tempoImune = maxTempoImune;
}

void Jogador::Executar()
{
    if(imune) {
        tempoImune--;
        if(tempoImune <= 0) imune = false;
    }
    
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void Jogador::Salvar() {}