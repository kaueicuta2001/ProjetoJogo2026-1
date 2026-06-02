#include "chao.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Chao::Chao(int id, sf::Vector2f windowSize) :
Obstaculo(id, Vector2f(0, windowSize.y - 32.f), false)
{
    tamanho = Vector2f(windowSize.x, 32.f);
    if (!textura.loadFromFile("../assets/chao.png"))
        std::cerr << "Erro ao carregar a textura do chão!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida

}

Chao::~Chao() {}

void Chao::Executar()
{
    sprite.setPosition(posicao);
    pGG->DesenhaSprite(&sprite);
}

void Chao::Salvar() {}
