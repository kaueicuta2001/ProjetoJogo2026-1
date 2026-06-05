#include "jogador.h"

using namespace sf;
using namespace std;

Jogador::Jogador(int id, sf::Vector2f pos) :
Personagem(id, pos),
pontos(0),
imune(false),
tempoImune(0),
maxTempoImune(180) // Duração da imunidade em frames (ex: 180 frames = 3 segundos a 60 FPS)
{
    nome = "Jogador";
    num_vidas = 100;
    dano = 10;
    vel = Vector2f(5.f, 5.f);
    tamanho = Vector2f(32.f, 32.f);
    if(!textura.loadFromFile("../assets/jogador1.png"))//botar imagem do jogador
        cerr << "Erro ao carregar a textura do jogador!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida
}

Jogador::~Jogador() {}

void Jogador::Mover()
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        posicao.x -= vel.x;
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        posicao.x += vel.x;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) && noChao)
    {
        Pular();
    }
    AplicarGravidade();
}

void Jogador::Pular() {
    vel.y = -12.f;
    noChao = false;
}

void Jogador::Pisar(Inimigo* inimigo) {
    if (inimigo) {
        inimigo->PerderVidas(dano);
        pontos += dano; // Incrementa os pontos do jogador a cada dano causado ao inimigo
    }
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

void Jogador::Executar()
{
    sprite.setPosition(posicao);
    Mover();
    AtualizarImunidade();
    Desenhar();
}

void Jogador::Salvar() {}
