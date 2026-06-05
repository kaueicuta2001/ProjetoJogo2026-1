#include "vespa.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

Vespa::Vespa(int id, sf::Vector2f pos, float dist) :
Inimigo(id, pos),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    vel = Vector2f(1.5f, 0.f);
    tamanho = Vector2f(60, 60);
    num_vidas = 2;
    nivel_maldade = 2;
    if (!textura.loadFromFile("../assets/vespa.png"))
        cerr << "Erro ao carregar a textura do vespa!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida
}

Vespa::~Vespa() {}

void Vespa::Mover()
{
    posicao.x += vel.x * direcao;

    if (posicao.x > limiteDir)
    {
        direcao = -1;
    }
    else if (posicao.x < limiteEsq)
    {
        direcao = 1;
    }

    AplicarGravidade();
}

void Vespa::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenhaSprite(&sprite);
}

void Vespa::Salvar() {}
