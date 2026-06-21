#include "chao.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;
using namespace TheFrog::Entidades;

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
    Gravitropismo();
    AplicarGravidade();

    sprite.setPosition(posicao);
    Desenhar(); 
}

void Chao::Salvar() {}