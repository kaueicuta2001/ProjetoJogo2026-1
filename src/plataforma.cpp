#include "plataforma.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"

using namespace sf;
using namespace std;
using namespace TheFrog::Entidades::Obstaculos;

Plataforma::Plataforma(int id, sf::Vector2f pos) : 
Obstaculo(id, pos), 
tempo(180)
{
    nome = "Plataforma";
    colideInimigo = true;
    tamanho = sf::Vector2f(75.f, 25.f);
    if (!textura.loadFromFile("../assets/plataforma.png"))
        std::cerr << "Erro ao carregar a textura da plataforma!" << endl;
    InicializarSprite(textura);
}

Plataforma::~Plataforma() {}

void Plataforma::DeslizarJogador(Personagens::Jogador* pJogador)
{
    pJogador->setPosicao(sf::Vector2f(pJogador->getPosicao().x + 1.f, pJogador->getPosicao().y));
}

void Plataforma::Obstaculizar(Personagens::Jogador* pJogador)
{
    DeslizarJogador(pJogador);
}

void Plataforma::AtualizarColisao()
{
    if(!colide) {
        int visivel = tempo % 5 == 0 ? 255 : 128; // Pisca entre visível e semi-transparente
        sprite.setColor(Color(255, 255, 255, visivel)); // Transparente quando invisível
    }
    else {
        sprite.setColor(Color(255, 255, 255, 255)); // Totalmente visível
    }
}

void Plataforma::Executar()
{
    Gravitropismo();
    AplicarGravidade();

    if(tempo > 0)
        tempo--;
    else{
        tempo = 300;
        colide = !colide;
    }
    AtualizarColisao();
    sprite.setPosition(posicao);
    Desenhar(); 
}

void Plataforma::Salvar() {}