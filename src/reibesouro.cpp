#include "reibesouro.h"
#include "gerenciadorgrafico.h"
#include "projetil.h"
#include "jogador.h"

using namespace sf;
using namespace std;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Entidades;
using namespace TheFrog::Entidades::Personagens;

ReiBesouro::ReiBesouro(int id, Vector2f pos, Jogador* pJogador, Jogador* pJogador2) :
Inimigo(id, pos),
estadoAtual(EstadoIA::Patrulhando),
maldade(false),
forca(5),
raioDeteccao(350.f),
limiteDir(pos.x + 10.f),
limiteEsq(pos.x - 10.f),
direcao(1),
atirar(false),
tempoTiro(0),
maxTempoTiro(300),
pProjetil(nullptr),
pJogadorAlvo(nullptr),
pJogador(pJogador),
pJogador2(pJogador2)
{
    vel = Vector2f(1.f, 0.f);
    tamanho = Vector2f(80.f, 80.f);
    posicao = pos;
    num_vidas = 100;
    nivel_maldade = 3;
    dano = forca * nivel_maldade;
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

void ReiBesouro::setProjetil(Projetil* proj){
    pProjetil = proj;
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
    if (estadoAtual == EstadoIA::Perseguindo && tempoTiro >= maxTempoTiro) {
        // distância entre o Rei Besouro e o jogador alvo
        Vector2f dir = Vector2f(pJogadorAlvo->getPosicao().x - posicao.x, pJogadorAlvo->getPosicao().y - posicao.y);
        
        // Normaliza o vetor (Calcula a hipotenusa e divide os eixos)
        float hipotenusa = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if (hipotenusa > 0.f) {
            direcaoTiro = Vector2f(dir.x / hipotenusa, dir.y / hipotenusa);
        } else {
            direcaoTiro = Vector2f(1.f, 0.f);
        }
        atirar = true; 
        tempoTiro = 0;
    }
}

void ReiBesouro::AprimorarMaldade()
{
    if(!maldade){
        dano += (nivel_maldade * forca);
        vel.x += 0.2f; 
        maldade = true;
    }
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
    tempoTiro += 1;
    if(tempoTiro >= maxTempoTiro)
        tempoTiro = maxTempoTiro; // Evita overflow
    VerificarAtaque();
    if(pProjetil && maldade) {
        pProjetil->AumentarDano(); 
    }    
    sprite.setPosition(posicao);
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
        --(*pJog);
        if(pJog->getPosicao().x > posicao.x)
            pJog->setPosicao(Vector2f(posicao.x + tamanho.x + 75.f, pJog->getPosicao().y - 75.f));
        else
            pJog->setPosicao(Vector2f(posicao.x - pJog->getTamanho().x - 75.f, pJog->getPosicao().y - 75.f));
    }
    AprimorarMaldade();
}

void ReiBesouro::ResetAtirar(){
    atirar = false;
}