#include "cogumelopulante.h"
#include "jogador.h"
#include "gerenciadorgrafico.h"

using namespace std;

CogumeloPulante::CogumeloPulante(int id, sf::Vector2f pos, bool danoso) :
Obstaculo(id, pos, danoso),
forcaimpulso(20.f)
{  
    tamanho = sf::Vector2f(64.f, 64.f);
    if (!textura.loadFromFile("../assets/cogumelopulante.png"))
        cerr << "Erro ao carregar a textura do cogumelo pulante!" << endl;
    InicializarSprite(textura);//parâmetro por refência escondida
}

CogumeloPulante::~CogumeloPulante() {}

void CogumeloPulante::Obstaculizar(Jogador* pJogador)
{
    pJogador->Pular();
    pJogador->setVelY(-forcaimpulso);
}

void CogumeloPulante::Executar()
{
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void CogumeloPulante::Salvar() {}
