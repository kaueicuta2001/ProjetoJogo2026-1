#include "chao.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Chao::Chao(int id, sf::Vector2f pos, int danoso) :
Obstaculo(id, pos, danoso),
altura(32.f),
largura(pGG->getWindow()->getSize().x)
{
    tamanho = Vector2f(largura, altura);
    if (!textura.loadFromFile("../assets/chao.png"))
        std::cerr << "Erro ao carregar a textura do chão!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida

}

Chao::~Chao() {}

void Chao::Obstaculizar(Jogador* pJogador)
{
}

void Chao::Executar()
{
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void Chao::Salvar() {}
