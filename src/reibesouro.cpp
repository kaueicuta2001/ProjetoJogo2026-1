#include "reibesouro.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

ReiBesouro::ReiBesouro(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
forca(100),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80, 80);
    num_vidas = 5;
    nivel_maldade = 3;
    if (!textura.loadFromFile("../assets/reibesouro.png"))
        std::cerr << "Erro ao carregar a textura do Rei Besouro!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida

}

ReiBesouro::~ReiBesouro() {}

void ReiBesouro::Mover()
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

void ReiBesouro::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenhaSprite(&sprite);
}

void ReiBesouro::Salvar() {}
