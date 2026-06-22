#include "vespa.h"
#include "gerenciadorgrafico.h"
#include "jogador.h"
#include <cmath>

using namespace sf;
using namespace std;
using namespace TheFrog::Entidades::Personagens;

Vespa::Vespa(int id, sf::Vector2f pos, float dist) :
Inimigo(id, pos),
angulo(0.f),
velocidadeAngular(0.03f),
amplitudeX(dist),         
amplitudeY(dist / 2.f),   
posInicial(pos),
glândulasVenenosas(false)           
{
    nome = "Vespa";
    vel = Vector2f(0.f, 0.f); 
    tamanho = Vector2f(64.f, 64.f);
    num_vidas = 40;
    nivel_maldade = 2;
    colideObstaculo = false;
    dano = 10;
    
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

void Vespa::AprimorarMaldade()
{
    dano = 2 * nivel_maldade;
    velocidadeAngular = 0.05f;
    AlterarSpriteMeiaVida();
}

void Vespa::AlterarSpriteMeiaVida()
{
    if (!textura.loadFromFile("../assets/vespameiavida.png"))
        cerr << "Erro ao carregar a textura da vespa meia vida!" << endl;
    sprite.setTexture(textura);
}

void Vespa::AtivarGlândulaVenenosa()
{
    glândulasVenenosas = true;
    AprimorarMaldade();
}

void Vespa::Danificar(Jogador* pJogador)
{
    if(pJogador != nullptr)
    {
        pJogador->PerderVidas(dano);
        --(*pJogador);
        pJogador->IniciarParalisia();
    }
}

void Vespa::Executar()
{
    if (num_vidas <= 20 && !glândulasVenenosas)
    {
        AtivarGlândulaVenenosa();
    }
    
    Mover();
    sprite.setPosition(posicao);    
    Desenhar(); 
}

void Vespa::Salvar() {}