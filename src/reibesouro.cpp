#include "reibesouro.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeColisoes.h"
#include "listaentidades.h"
#include "projetil.h"
#include "jogador.h"
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

ReiBesouro::ReiBesouro(int id, Vector2f pos, Jogador* pJogador, Jogador* pJogador2) :
Inimigo(id, pos),
estadoAtual(EstadoIA::Patrulhando),
forca(10),
raioDeteccao(100.f),
limiteDir(pos.x + 25.f),
limiteEsq(pos.x - 25.f),
direcao(1),
tempoTiro(600),       // Inicializa com 10 segundos em frames (10 * 60 FPS)
maxTempoTiro(600),    // Intervalo fixo de 10 segundos
pJogadorAlvo(nullptr),
pJogador(pJogador),
pJogador2(pJogador2)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80.f, 80.f);
    num_vidas = 100;
    nivel_maldade = 3;
    dano = 10;
    nome = "Rei Besouro";
    if (!textura.loadFromFile("../assets/reibesouro.png"))
        cerr << "Erro ao carregar a textura do Rei Besouro!" << endl;
    InicializarSprite(textura);
}

ReiBesouro::~ReiBesouro() {}

void ReiBesouro::AtualizarEstado()
{
    pJogadorAlvo = nullptr;
    float menorDistancia = raioDeteccao;

    if (pJogador) {
        float dist1 = std::sqrt(std::pow(pJogador->getPosicao().x - posicao.x, 2) + std::pow(pJogador->getPosicao().y - posicao.y, 2));
        if (dist1 < menorDistancia) { menorDistancia = dist1; pJogadorAlvo = pJogador; }
    }
    if (pJogador2) {
        float dist2 = std::sqrt(std::pow(pJogador2->getPosicao().x - posicao.x, 2) + std::pow(pJogador2->getPosicao().y - posicao.y, 2));
        if (dist2 < menorDistancia) { menorDistancia = dist2; pJogadorAlvo = pJogador2; }
    }

    estadoAtual = (pJogadorAlvo != nullptr) ? EstadoIA::Perseguindo : EstadoIA::Patrulhando;
}
sf::Vector2f ReiBesouro::getDirecaoTiro()
{
    return direcaoTiro;
}
void ReiBesouro::Mover()
{
    if (estadoAtual == EstadoIA::Patrulhando) {
        posicao.x += direcao * vel.x;
        if (posicao.x >= limiteDir) direcao = -1;
        else if (posicao.x <= limiteEsq) direcao = 1;
    } 
    else if (estadoAtual == EstadoIA::Perseguindo && pJogadorAlvo != nullptr) {
        if (pJogadorAlvo->getPosicao().x > posicao.x) posicao.x += vel.x;
        else posicao.x -= vel.x;
    }

    if(!noChao)
        AplicarGravidade();
}

void ReiBesouro::VerificarAtaque() {
    if (estadoAtual == EstadoIA::Perseguindo && pJogadorAlvo != nullptr) {
        tempoTiro += 1;
        if (tempoTiro >= maxTempoTiro) {
            direcaoTiro = Vector2f(pJogadorAlvo->getPosicao().x - posicao.x, pJogadorAlvo->getPosicao().y - posicao.y);
            atirar = true; 
            tempoTiro = 0;
        }
    }
}

void ReiBesouro::AprimorarMaldade()
{
    dano += (nivel_maldade * forca);
    AlterarSpriteMeiaVida();
}

void ReiBesouro::AlterarSpriteMeiaVida()
{
    if (!textura.loadFromFile("../assets/reibesouromeiavida.png"))
        cerr << "Erro ao carregar a textura do rei besouro meia vida!" << endl;
    sprite.setTexture(textura);
}

void ReiBesouro::Executar()
{
    AtualizarEstado();
    Mover();
    VerificarAtaque();
    Desenhar();
}

void ReiBesouro::Salvar()
{
}




void ReiBesouro::Danificar(Jogador* pJog)
{
    if (pJog)
    {
        pJog->PerderVidas(dano);
    }
    AprimorarMaldade();
}
bool ReiBesouro::getAtirar()
{
    if(atirar)
    {
        atirar = false; // Reseta a flag após o disparo
        return true;
    }
    return false;
}