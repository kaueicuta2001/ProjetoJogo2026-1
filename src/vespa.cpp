#include "vespa.h"
#include "gerenciadorgrafico.h"
#include "jogador.h" // Necessário para a Vespa conseguir ferir o Jogador
#include <cmath>

using namespace sf;
using namespace std;

Vespa::Vespa(int id, sf::Vector2f pos, float dist) :
Inimigo(id, pos),
angulo(0.f),
velocidadeAngular(0.03f),
amplitudeX(dist),         
amplitudeY(dist / 2.f),   
posInicial(pos)           
{
    nome = "Vespa";
    vel = Vector2f(0.f, 0.f); 
    tamanho = Vector2f(64.f, 64.f);
    num_vidas = 2;
    nivel_maldade = 2;
    dano = 1; // O dano que a Vespa causa ao encostar no Sapo
    
    if (!textura.loadFromFile("../assets/vespa.png"))
        cerr << "Erro ao carregar a textura da vespa!" << endl;
    InicializarSprite(textura);
}

Vespa::~Vespa() {}

void Vespa::Mover()
{
    angulo += velocidadeAngular;

    if (angulo > 6.28318f)//caso o valor do ângulo ultrapasse 2*PI, reseta para evitar overflow
    {
        angulo -= 6.28318f;
    }

    posicao.x = posInicial.x + amplitudeX * cos(angulo);
    posicao.y = posInicial.y + amplitudeY * sin(2.f * angulo);
    AplicarGravidade();
}

void Vespa::AprimorarMaldade() {}

void Vespa::Danificar(Jogador* pJogador)
{
    if(pJogador != nullptr)
    {
        pJogador->PerderVidas(dano);
    }
}

void Vespa::Executar()
{
    Mover();
    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

void Vespa::Salvar() {}