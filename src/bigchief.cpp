#include "bigchief.h"
#include "gerenciadorgrafico.h"

using namespace sf;
using namespace std;

BigChief::BigChief(int id, Vector2f pos, float dist) :
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
    if (!textura.loadFromFile("../assets/bigchief.png"))
        std::cerr << "Erro ao carregar a textura do Big Chief!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida

}

BigChief::~BigChief() {}

void BigChief::Mover()
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

void BigChief::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenhaSprite(&sprite);
}

void BigChief::Salvar() {}
