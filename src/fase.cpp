#include "fase.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeEventos.h"
#include <iostream>

using namespace std;
using namespace sf;
using namespace TheFrog::Fases;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Listas;
using namespace TheFrog::Entidades;
using namespace TheFrog::Entidades::Obstaculos;
using namespace TheFrog::Entidades::Personagens;

Fase::Fase(int id, Entidades::Personagens::Jogador* jogador, Entidades::Personagens::Jogador* jogador2) :
Ente(id),
listaEntidades(),
gerenciadorColisoes(jogador, jogador2),
pJogador(jogador),
pJogador2(jogador2),
barraLargura(200.f),
barraAltura(20.f),
margem(7.5f),
maxBesouros(5),
maxPlataformas(5),
maxObstDificil(5),
faseAtiva(true),
ganhou(false)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());

    relogioFase.restart(); 

    if (pJogador) {
        listaEntidades.Incluir(pJogador);
    }
    if (pJogador2) {
        listaEntidades.Incluir(pJogador2);
    }

    InicializarBarrasDeVida();

    Gerenciadores::GerenciadorDeEventos::getGerenciadorDeEventos()->Anexar(this);
}

Fase::~Fase()
{
    Gerenciadores::GerenciadorDeEventos::getGerenciadorDeEventos()->Desanexar(this);
    listaEntidades.Limpar();
}

int Fase::getTempoJogado() const
{
    return static_cast<int>(relogioFase.getElapsedTime().asSeconds());
}

void Fase::Notificar(sf::Event evento)
{
    if(evento.type == Event::KeyPressed)
    {
        if(evento.key.code == Keyboard::Escape)
        {
            pGG->FecharJanela();
        }
    }
}

void Fase::CriarCenario()
{
    sprite.setTexture(textura);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );

    Chao* chao = new Chao(1, Vector2f(0.f, tamanho.y - 32.f), false);
    listaEntidades.Incluir(chao);
    gerenciadorColisoes.IncluirChao(chao);
}

void Fase::CriarBesouros()
{
    int numBesouros = (rand() % (maxBesouros - 2)) + 3; 
    for (int i = 0; i < numBesouros; i++)
    {
        Entidades::Personagens::Besouro* pBesouro = new Entidades::Personagens::Besouro(i + 10, Vector2f(100.f + (i * 200.f), 100.f), 100.f);
        listaEntidades.Incluir(pBesouro);
        gerenciadorColisoes.IncluirInimigo(pBesouro);
    }
}

void Fase::CriarPlataformas()
{
    float posicoesY[5] = {600.f, 500.f, 400.f, 300.f, 400.f};

    int numPlataformas = (rand() % (maxPlataformas - 2)) + 3; 
    for (int i = 0; i < numPlataformas; i++)
    {
        Plataforma* pPlataforma = new Plataforma(i + 20, Vector2f(150.f + (i * 150.f), posicoesY[i]));
        listaEntidades.Incluir(pPlataforma);
        gerenciadorColisoes.IncluirObstaculo(pPlataforma);
    }
}

void Fase::InicializarBarrasDeVida()
{
    if(!fonteVida.loadFromFile("../assets/Frijole-Regular.ttf"))
        cerr << "Erro ao carregar a fonte de vida!" << endl;
        
    //fundo da barra de vida do jogador 1
    fundoBarraj1.setSize(Vector2f(barraLargura + margem * 2, barraAltura + margem * 2));
    fundoBarraj1.setFillColor(Color(50, 50, 50));
    fundoBarraj1.setPosition(margem, margem);

    //barra de vida do jogador 1
    barraVidaj1.setSize(Vector2f(pJogador->getVidas() * (barraLargura / 100.0f), barraAltura));
    barraVidaj1.setFillColor(Color(200, 0, 0));
    barraVidaj1.setPosition(margem * 2, margem * 2);

    textoVidaJ1.setFont(fonteVida);
    textoVidaJ1.setString("Vida J1: " + to_string(pJogador->getVidas()) + "/100");
    textoVidaJ1.setCharacterSize(10);
    textoVidaJ1.setPosition(margem * 2, margem * 2);

    if (pJogador2) {
        //fundo da barra de vida do jogador 2
        fundoBarraj2.setSize(Vector2f(barraLargura + margem * 2, barraAltura + margem * 2));
        fundoBarraj2.setFillColor(Color(50, 50, 50));
        fundoBarraj2.setPosition(tamanho.x - barraLargura - margem * 3, margem);

        //barra de vida do jogador 2
        barraVidaj2.setSize(Vector2f(pJogador2->getVidas() * (barraLargura / 100.0f), barraAltura));
        barraVidaj2.setFillColor(Color(200, 0, 0));
        barraVidaj2.setPosition(tamanho.x - barraLargura - margem * 2, margem * 2);

        textoVidaJ2.setFont(fonteVida);
        textoVidaJ2.setString("Vida J2: " + to_string(pJogador2->getVidas()) + "/100");
        textoVidaJ2.setCharacterSize(10);
        textoVidaJ2.setPosition(tamanho.x - barraLargura - margem * 2, margem * 2);
    }
}

void Fase::AtualizarBarrasDeVida()
{
    barraVidaj1.setSize(Vector2f(pJogador->getVidas() * (barraLargura / 100.0f), barraAltura));
    textoVidaJ1.setString("Vida J1: " + to_string(pJogador->getVidas()) + "/100");

    if (pJogador2) {
        barraVidaj2.setSize(Vector2f(pJogador2->getVidas() * (barraLargura / 100.0f), barraAltura));
        textoVidaJ2.setString("Vida J2: " + to_string(pJogador2->getVidas()) + "/100");
    }
}

void Fase::DesenharBarrasDeVida()
{
    pGG->getWindow()->draw(fundoBarraj1);
    pGG->getWindow()->draw(barraVidaj1);
    pGG->getWindow()->draw(textoVidaJ1);

    if (pJogador2) {
        pGG->getWindow()->draw(fundoBarraj2);
        pGG->getWindow()->draw(barraVidaj2);
        pGG->getWindow()->draw(textoVidaJ2);
    }
}

void Fase::VerificarEstadoFase()
{
    if (pJogador && pJogador->getVidas() <= 0)
    {
        cout << "GAME OVER! Jogador 1 foi derrotado!" << endl;
        faseAtiva = false;
        ganhou = false;
    }
    
    if (pJogador2 && pJogador2->getVidas() <= 0)
    {
        cout << "GAME OVER! Jogador 2 foi derrotado!" << endl;
        faseAtiva = false;
        ganhou = false;
    }
    
    if (ContarInimigosVivos() <= 0)
    {
        cout << "VITORIA! Todos os inimigos foram derrotados!" << endl;
        faseAtiva = false;
        ganhou = true;
    }
}

int Fase::ContarInimigosVivos()
{
    int countInimigos = 0;
    Lista<Entidade>::Elemento* atual = listaEntidades.getPrimeiro();
    
    while (atual != nullptr)
    {
        Entidade* pEnt = atual->getInfo();
        if (pEnt->getNome() == "Besouro" || pEnt->getNome() == "Vespa" || pEnt->getNome() == "Rei Besouro")
        {
            if (pEnt->getVivo()) {
                countInimigos++;
            }
        }
        atual = atual->getProximo();
    }
    return countInimigos;
}

bool Fase::getFaseAtiva() const
{
    return faseAtiva;
}

bool Fase::getGanhou() const
{
    return ganhou;
}

void Fase::Executar()
{
    AtualizarBarrasDeVida();
    DesenharBarrasDeVida();
    VerificarEstadoFase();
    if(pJogador)
        if(pJogador->getPosicao().y > tamanho.y)
            pJogador->PerderVidas(101);
    if(pJogador2)
        if(pJogador2->getPosicao().y > tamanho.y)
            pJogador2->PerderVidas(101);
}