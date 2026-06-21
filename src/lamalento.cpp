#include "lamalento.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace std;

LamaLento::LamaLento(int id, sf::Vector2f pos) :
Obstaculo(id, pos),
lentidao(0.1f)
{  
    tamanho = sf::Vector2f(50.f, 25.f);
    nome = "Lama Lento";
    if (!textura.loadFromFile("../assets/lamalento.png"))
        cerr << "Erro ao carregar a textura da lama lenta!" << endl;
    InicializarSprite(textura);
}

LamaLento::~LamaLento() {}

void LamaLento::Obstaculizar(Jogador* pJogador)
{
    LentificarJogador(pJogador);
}

void LamaLento::LentificarJogador(Jogador* pJogador)
{
    pJogador->setVelX(pJogador->getVelX() * lentidao);
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
