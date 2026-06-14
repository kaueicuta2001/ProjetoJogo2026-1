#include "chao.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Chao::Chao(int id, sf::Vector2f pos, bool danoso) :
Entidade(id, pos),
altura(32.f),
largura(pGG->getWindow()->getSize().x),
danoso(danoso)
{
    nome = "Chao";
    tamanho = Vector2f(largura, altura);
    if (!textura.loadFromFile("../assets/chao.png"))
        std::cerr << "Erro ao carregar a textura do chão!" << endl;
    InicializarSprite(textura);
}

Chao::~Chao() {}

void Chao::Executar()
{
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void Chao::Salvar() {}
