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

ReiBesouro::ReiBesouro(int id, Vector2f pos, float dist) :
Inimigo(id, pos),
forca(100),
distancia(dist),
limiteDir(pos.x + distancia),
limiteEsq(pos.x - distancia),
direcao(1),
carapaçaEndurecida(false),
tempoTiro(600),       // Inicializa com 10 segundos em frames (10 * 60 FPS)
maxTempoTiro(600),    // Intervalo fixo de 10 segundos
pGerenciadorColisoes(nullptr),
pListaEntidades(nullptr)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80.f, 80.f);
    num_vidas = 100;
    nivel_maldade = 3;
    dano = 10;
    nome = "Rei Besouro";
    if (!textura.loadFromFile("../assets/reibesouro.png"))
        std::cerr << "Erro ao carregar a textura do Rei Besouro!" << endl;
    InicializarSprite(textura);
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

void ReiBesouro::AprimorarMaldade()
{
    dano *= 2;
    AlterarSpriteMeiaVida();
}

void ReiBesouro::AlterarSpriteMeiaVida()
{
    if (!textura.loadFromFile("../assets/reibesouromeiavida.png"))
        cerr << "Erro ao carregar a textura do rei besouro meia vida!" << endl;
    sprite.setTexture(textura);
}

void ReiBesouro::Atirar()
{
    if (!pGerenciadorColisoes || !pListaEntidades) return;

    Jogador* jogadorAlvo = nullptr;
    float distMin = 1e9f;

    // Mede a distância do Jogador 1
    if (pGerenciadorColisoes->pJogador && pGerenciadorColisoes->pJogador->getVivo())
    {
        Vector2f posJ1 = pGerenciadorColisoes->pJogador->getPosicao();
        float dist1 = sqrt(pow(posJ1.x - posicao.x, 2) + pow(posJ1.y - posicao.y, 2));
        if (dist1 < distMin)
        {
            distMin = dist1;
            jogadorAlvo = pGerenciadorColisoes->pJogador;
        }
    }

    // Mede a distância do Jogador 2 para verificar quem está mais perto
    if (pGerenciadorColisoes->pJogador2 && pGerenciadorColisoes->pJogador2->getVivo())
    {
        Vector2f posJ2 = pGerenciadorColisoes->pJogador2->getPosicao();
        float dist2 = sqrt(pow(posJ2.x - posicao.x, 2) + pow(posJ2.y - posicao.y, 2));
        if (dist2 < distMin)
        {
            jogadorAlvo = pGerenciadorColisoes->pJogador2;
        }
    }

    // Se houver algum jogador válido por perto, calcula a direção e atira
    if (jogadorAlvo)
    {
        Vector2f posProjetil = Vector2f(
            posicao.x + (direcao > 0 ? tamanho.x : -26.6f),
            posicao.y + tamanho.y / 2.f - 13.3f
        );

        // Calcula o vetor de direção em direção ao alvo
        Vector2f dir = jogadorAlvo->getPosicao() - posProjetil;
        float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);
        
        if (magnitude != 0.f)
            dir /= magnitude; // Normaliza o vetor para manter velocidade constante

        Projetil* pProjetil = new Projetil(id * 1000 + tempoTiro, posProjetil, dir, 5);

        if (carapaçaEndurecida)
        {
            pProjetil->AumentarDano();
        }

        pListaEntidades->Incluir(pProjetil); // <-- Corrigido para Incluir
        pGerenciadorColisoes->IncluirProjetil(pProjetil); 
    }
}

void ReiBesouro::Executar()
{
    Mover();

    // Contador baseado no framerate de 60 FPS (600 frames = 10 segundos)
    if (tempoTiro > 0)
    {
        tempoTiro--;
    }
    else
    {
        Atirar();
        tempoTiro = maxTempoTiro; 
    }

    sprite.setPosition(posicao);
    pGG->DesenharEnte(&sprite);
}

// ==========================================
// FUNÇÕES QUE FALTAVAM PARA O LINKER (C++)
// ==========================================

void ReiBesouro::setGerenciadorColisoes(GerenciadorDeColisoes* pGC)
{
    pGerenciadorColisoes = pGC;
}

void ReiBesouro::setListaEntidades(ListaEntidades* pLE)
{
    pListaEntidades = pLE;
}

void ReiBesouro::Salvar()
{
    // Método obrigatório da herança, pode deixar vazio se não for usar agora
}

void ReiBesouro::Danificar(Jogador* pJogador)
{
    if (pJogador)
    {
        pJogador->PerderVidas(dano);
    }
}