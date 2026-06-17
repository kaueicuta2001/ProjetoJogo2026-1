#include "plataforma.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"

using namespace sf;
using namespace std;

Plataforma::Plataforma(int id, sf::Vector2f pos, bool danoso) : 
Obstaculo(id, pos, danoso), 
tempo(180)
{
    tamanho = sf::Vector2f(75.f, 25.f);
    if (!textura.loadFromFile("../assets/plataforma.png"))
        std::cerr << "Erro ao carregar a textura da plataforma!" << endl;
    InicializarSprite(textura);
}

Plataforma::~Plataforma() {}

void Plataforma::Obstaculizar(Jogador* pJogador)
{
    pJogador->setPosicao(sf::Vector2f(pJogador->getPosicao().x + 1.f, pJogador->getPosicao().y));//desliza para direita

    if(tempo > 0)
        tempo--;
    else
        Desativar();
}

void Plataforma::Executar()
{
    Gravitropismo();
    AplicarGravidade();

    sprite.setPosition(posicao);
    Desenhar(); 
}

void Plataforma::Salvar() {}