#include "lamalento.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace TheFrog::Entidades::Obstaculos;

LamaLento::LamaLento(int id, sf::Vector2f pos) :
Obstaculo(id, pos),
lentidao(0.005f)
{  
    tamanho = sf::Vector2f(50.f, 25.f);
    nome = "Lama Lento";
    if (!textura.loadFromFile("../assets/lamalento.png"))
        cerr << "Erro ao carregar a textura da lama lenta!" << endl;
    InicializarSprite(textura);
}

LamaLento::~LamaLento() {}

void LamaLento::Obstaculizar(Personagens::Jogador* pJogador)
{
    LentificarJogador(pJogador);
}

void LamaLento::LentificarJogador(Personagens::Jogador* pJogador)
{
    pJogador->setVelX(lentidao);
}

void LamaLento::Executar()
{
    Gravitropismo();
    AplicarGravidade();

    if (vidasJogador <= 50) {
        lentidao = 0.05f; 
    }

    sprite.setPosition(posicao);
    Desenhar(); 
}

void LamaLento::Salvar() {}
