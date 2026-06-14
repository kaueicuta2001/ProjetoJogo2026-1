#include "jogo.h"

using namespace sf;
using namespace std;

Jogo::Jogo() :
estadoAtual(EstadoJogo::MenuPrincipal),
opcaoMenuPrincipal(-1),
opcaoMenuFase(-1),
GG(GerenciadorGrafico::getGerenciadorGrafico()),
pJogador(nullptr),
pJogador2(nullptr),
menuPrincipal(nullptr),
menuFase(nullptr),
faseAtual(nullptr)
{
    Ente::setGG(GG);
    menuPrincipal = new MenuPrincipal(1, this);
    menuFase = new MenuFase(2, this);
}

Jogo::~Jogo() {
    if(faseAtual)
        delete faseAtual;
    if(menuPrincipal)
        delete menuPrincipal;
    if(menuFase)
        delete menuFase;
}

void Jogo::setOpcaoMenuPrincipal(int opcao) {
    opcaoMenuPrincipal = opcao;
}

void Jogo::setOpcaoMenuFase(int opcao) {
    opcaoMenuFase = opcao;
}


void Jogo::Executar()
{
    while (GG->VerificaJanelaAberta())
    {
        GG->LimpaJanela();

        switch (estadoAtual)
        {
            case EstadoJogo::MenuPrincipal:
                if (menuPrincipal) {
                    menuPrincipal->Executar();
                    if (menuPrincipal->getSelecionado()) {
                        if (opcaoMenuPrincipal == 2) {
                            GG->FecharJanela();
                        } if (opcaoMenuPrincipal == 1) {
                            pJogador2 = new Jogador(6, Vector2f(100.f, 50.f), true);
                        } if (opcaoMenuPrincipal >= 0) {
                        pJogador = new Jogador(5, Vector2f(100.f, 50.f), false);
                        estadoAtual = EstadoJogo::MenuFase;
                        }
                    }
                }
                else {
                    cerr << "Menu atual é nulo!" << endl;
                    GG->FecharJanela();
                }
                break;
            case EstadoJogo::MenuFase:
                if (menuFase) {
                    menuFase->Executar();
                    if (menuFase->getSelecionado()) {
                        if (opcaoMenuFase == 0) {
                            faseAtual = new Fase1(3, pJogador, pJogador2);
                        } else if (opcaoMenuFase == 1) {
                            faseAtual = new Fase2(4, pJogador, pJogador2);
                        } else if (opcaoMenuFase == 2) {
                            estadoAtual = EstadoJogo::MenuPrincipal;
                        }
                        estadoAtual = EstadoJogo::Jogando;
                    }
                }
                else {
                    cerr << "Menu atual é nulo!" << endl;
                    GG->FecharJanela();
                }
                break;
            case EstadoJogo::Jogando:
                if (faseAtual) {
                    faseAtual->Executar();
                }
                else {
                    cerr << "Fase atual é nula!" << endl;
                    GG->FecharJanela();
                }
                break;
            case EstadoJogo::Sair:
                GG->FecharJanela();
                break;
        }
        GG->Renderizar();
    }
}