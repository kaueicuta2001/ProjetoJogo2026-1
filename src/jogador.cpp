#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Jogador::Jogador(int id, sf::Vector2f pos) :
Personagem(id, pos),
pontos(0)
{
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
        vel.y = -12.f;
        noChao = false;
    }
    AplicarGravidade();
}

void Jogador::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenhaSprite(&sprite);
}

void Jogador::Salvar() {}
