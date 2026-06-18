#include "lamalento.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace std;

LamaLento::LamaLento(int id, sf::Vector2f pos) :
Obstaculo(id, pos),
lentidao(0.5f)
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
    pJogador->setPosicao(pJogador->getPosicao() + sf::Vector2f(pJogador->getVelX() * lentidao, 0.f));
}

void LamaLento::Executar()
{
    Gravitropismo();
    AplicarGravidade();

    sprite.setPosition(posicao);
    Desenhar(); 
}

void LamaLento::Salvar() {}