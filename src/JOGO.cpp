#include "jogo.h"
#include "gerenciadordearquivos.h"

using namespace sf;
using namespace std;
using namespace TheFrog;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Menus;
using namespace TheFrog::Fases;
using namespace TheFrog::Entidades::Personagens;

Jogo::Jogo() :
GG(GerenciadorGrafico::getGerenciadorGrafico()),
GE(GerenciadorDeEventos::getGerenciadorDeEventos()),
pJogador(nullptr),
pJogador2(nullptr),
faseAtual(nullptr),
menuPrincipal(nullptr),
menuFase(nullptr),
menuRanking(nullptr),
menuNome(nullptr),
estadoAtual(EstadoJogo::MenuPrincipal),
opcaoMenuPrincipal(-1),
opcaoMenuFase(-1),
qtdJogadores(1),
nomeJogador("")
{
    Ente::setGG(GG);
    menuPrincipal = new MenuPrincipal(1, this);
    menuFase = new MenuFase(2, this);
    menuRanking = new MenuRanking(5, this);
    menuNome = new MenuNome(6, this);

    menuPrincipal->setAtivo(true); 
    menuFase->setAtivo(false);
    menuRanking->setAtivo(false);
    menuNome->setAtivo(false);
}

Jogo::~Jogo() {
    if(faseAtual) delete faseAtual;
    if(menuPrincipal) delete menuPrincipal;
    if(menuFase) delete menuFase;
    if(menuRanking) delete menuRanking;
    if(menuNome) delete menuNome;
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
        GE->Executar(); 
        GG->LimpaJanela();

        switch (estadoAtual)
        {
            case EstadoJogo::MenuPrincipal:
                if (menuPrincipal) {
                    menuPrincipal->Executar();

                    if (opcaoMenuPrincipal == -2) {
                        opcaoMenuPrincipal = -1; 
                    }
                    
                    if (menuPrincipal->getSelecionado()) {
                        if (opcaoMenuPrincipal == 0 || opcaoMenuPrincipal == 1) {
                            qtdJogadores = (opcaoMenuPrincipal == 0) ? 1 : 2;
                            estadoAtual = EstadoJogo::MenuNome;
                            menuPrincipal->setAtivo(false); 
                            menuNome->resetNome(); // Limpa a caixa de texto
                            menuNome->setAtivo(true);
                        } else if (opcaoMenuPrincipal == 2) {
                            estadoAtual = EstadoJogo::Ranking;
                            menuPrincipal->setAtivo(false);
                            menuRanking->AtualizarRanking();
                            menuRanking->setAtivo(true);
                        } else if (opcaoMenuPrincipal == 3) {
                            estadoAtual = EstadoJogo::Sair;
                        }
                        menuPrincipal->resetSelecionado();
                    }
                }
                break;
                
            case EstadoJogo::MenuNome:
                if (menuNome) {
                    menuNome->Executar();
                    if (menuNome->getSelecionado()) {
                        nomeJogador = menuNome->getNomeDigitado();
                        
                        // Agora sim, instanciamos os jogadores!
                        pJogador = new Jogador(1, Vector2f(50.f, 300.f), false);
                        if (qtdJogadores == 2) {
                            pJogador2 = new Jogador(2, Vector2f(150.f, 300.f), true);
                        } else {
                            pJogador2 = nullptr;
                        }
                        
                        estadoAtual = EstadoJogo::MenuFase;
                        menuNome->setAtivo(false);
                        menuFase->setAtivo(true);
                        menuNome->resetSelecionado();
                    }
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
                            menuFase->setAtivo(false);
                            menuPrincipal->setAtivo(true);
                            
                            // Cancela os jogadores alocados
                            delete pJogador; pJogador = nullptr;
                            if (pJogador2) { delete pJogador2; pJogador2 = nullptr; }
                        }
                        
                        if (opcaoMenuFase != 2) {
                            estadoAtual = EstadoJogo::Jogando;
                            menuFase->setAtivo(false); 
                        }
                        menuFase->resetSelecionado();
                    }
                }
                break;
                
            case EstadoJogo::Ranking:
                if (menuRanking) {
                    menuRanking->Executar();
                    if (opcaoMenuPrincipal == -2) {
                        estadoAtual = EstadoJogo::MenuPrincipal;
                        menuRanking->setAtivo(false);
                        menuPrincipal->setAtivo(true);
                        opcaoMenuPrincipal = -1; 
                    }
                }
                break;
                
            case EstadoJogo::Jogando:
                if (faseAtual) {
                    faseAtual->Executar();
                    
                    if (!faseAtual->getFaseAtiva()) {
                        int pontosFinais = pJogador->getPontos();
                        if (pJogador2) pontosFinais += pJogador2->getPontos();
                        int tempoFinal = faseAtual->getTempoJogado();
                        int faseJogada = (opcaoMenuFase == 0) ? 1 : 2;
                        
                        GerenciadorDeArquivos::SalvarPontuacao(nomeJogador, pontosFinais, tempoFinal, qtdJogadores, faseJogada);
                        
                        delete faseAtual;
                        faseAtual = nullptr;
                        pJogador = nullptr;
                        pJogador2 = nullptr;
                        estadoAtual = EstadoJogo::MenuPrincipal;
                        menuPrincipal->setAtivo(true);
                    }
                }
                break;                
            case EstadoJogo::Sair:
                GG->FecharJanela();
                return;
        }
        GG->Renderizar();
    }
}