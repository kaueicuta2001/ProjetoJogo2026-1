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
raioDeteccao(350.f),
limiteDir(pos.x + 10.f),
limiteEsq(pos.x - 10.f),
direcao(1),
atirar(false),
tempoTiro(600),       // Inicializa com 10 segundos em frames (10 * 60 FPS)
maxTempoTiro(600),    // Intervalo fixo de 10 segundos
pJogadorAlvo(nullptr),
pJogador(pJogador),
pJogador2(pJogador2)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80.f, 80.f);
    posicao = pos;
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

bool ReiBesouro::getAtirar() const{
    return atirar;
}

Vector2f ReiBesouro::getDirecaoTiro(){
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
            // 1. Calcula o vetor de distância pura
            Vector2f dir = Vector2f(pJogadorAlvo->getPosicao().x - posicao.x, pJogadorAlvo->getPosicao().y - posicao.y);
            
            // 2. Normaliza o vetor (Calcula a hipotenusa e divide os eixos)
            float hipotenusa = std::sqrt(dir.x * dir.x + dir.y * dir.y);
            if (hipotenusa > 0.f) {
                direcaoTiro = Vector2f(dir.x / hipotenusa, dir.y / hipotenusa);
            } else {
                direcaoTiro = Vector2f(1.f, 0.f); // Padrão se estiver exatamente na mesma coordenada
            }

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
    sprite.setPosition(posicao);
    Desenhar();
}

void ReiBesouro::Salvar()
{
    // Método obrigatório da herança, pode deixar vazio se não for usar agora
}

void ReiBesouro::Danificar(Jogador* pJog)
{
    if (pJog)
    {
        pJog->PerderVidas(dano);
    }
    AprimorarMaldade();
}

void ReiBesouro::ResetAtirar(){
    atirar = false;
}