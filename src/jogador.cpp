#include "jogador.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;
using namespace TheFrog::Entidades::Personagens;

Jogador::Jogador(int id, sf::Vector2f pos, bool isJogador2) :
Personagem(id, pos),
pontos(0),
imune(false),
tempoImune(0),
velLentidao(0.f),
lentidao(false),
tempoParalisia(0),
paralisia(false),
jogador2(isJogador2),
velOriginal(Vector2f(5.f, 5.f))
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

    if(!noChao)
        AplicarGravidade();
}

void Jogador::Pular() {
    vel.y = -10.f;
    noChao = false;
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
    tempoImune = 180;
}

void Jogador::IniciarLentidao(float fator) {
    velLentidao = fator;
    lentidao = true;
}

void Jogador::AtualizarLentidao() {
    vel.x = lentidao ? velLentidao : velOriginal.x;
    lentidao = false;
}

void Jogador::IniciarParalisia() {
    tempoParalisia = 120;
    paralisia = true;
}

void Jogador::AtualizarParalisia() {
    if(paralisia){
        vel.x = 0.f;
        tempoParalisia--;
        noChao = false;
        if(tempoParalisia <= 0){
            paralisia = false;
            vel = velOriginal;
        }
    }
}

void Jogador::AtualizarImunidade() {
    if (imune && tempoImune > 0) {
        int visivel = tempoImune % 5 == 0 ? 255 : 128; // Pisca entre visível e semi-transparente
        sprite.setColor(Color(255, 255, 255, visivel)); // Transparente quando invisível
        tempoImune--;
    } else {
        imune = false;
        sprite.setColor(Color(255, 255, 255, 255)); // Volta a ser totalmente visível
    }
}

Jogador& Jogador::operator--() {
    if(pontos > 0) 
        pontos--;
    return *this;
}

void Jogador::setVelY(float vY)
{
    vel.y = vY;
}

float Jogador::getVelX() const
{
    return vel.x;
}
void Jogador::setVelX(float vX)
{
    vel.x = vX;
}

void Jogador::Executar()
{    
    sprite.setPosition(posicao);
    AtualizarLentidao();
    AtualizarParalisia();
    Mover();
    AtualizarImunidade();
    Desenhar();
}

void Jogador::Salvar() {}

int Jogador::getPontos() const {
    return pontos;
}