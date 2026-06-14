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
    InicializarSprite(textura);//parâmetro por refência escondida
}

Plataforma::~Plataforma() {}

 void Plataforma::Obstaculizar(Jogador* pJogador)
{
    if(tempo > 0)
        tempo--;
    else
        Desativar();
}

void Plataforma::Executar()
{
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void Plataforma::Salvar() {}
