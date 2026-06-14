#pragma once

#include "gerenciadorgrafico.h"
#include "jogador.h"
#include "menuprincipal.h"
#include "menufase.h"
#include "fase.h"
#include "fase1.h"
#include "fase2.h"
#include "gerenciadorDeColisoes.h"

class Jogo
{
public:
    enum class EstadoJogo
    {
        MenuPrincipal,
        MenuFase,
        Jogando, 
        Sair
    };
private:
    EstadoJogo estadoAtual;
    int opcaoMenuPrincipal;
    int opcaoMenuFase;
    GerenciadorGrafico* GG;
    Jogador* pJogador;
    Jogador* pJogador2;
    MenuPrincipal* menuPrincipal;
    MenuFase* menuFase;
    Fase* faseAtual;
public:
    Jogo();
    ~Jogo();
    void setOpcaoMenuPrincipal(int opcao);
    void setOpcaoMenuFase(int opcao);
    void Executar();
};
