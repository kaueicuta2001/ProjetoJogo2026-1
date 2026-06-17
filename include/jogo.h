#pragma once
#include "gerenciadorgrafico.h"
#include "gerenciadorDeEventos.h"
#include "fase1.h"
#include "fase2.h"
#include "menuprincipal.h"
#include "menufase.h"
#include "menuranking.h"
#include "menunome.h"

enum class EstadoJogo {
    MenuPrincipal,
    MenuNome, 
    MenuFase,
    Ranking, 
    Jogando,
    Sair
};

class Jogo {
private:
    GerenciadorGrafico* GG;
    GerenciadorDeEventos* GE;
    Jogador* pJogador;
    Jogador* pJogador2;
    Fase* faseAtual;
    MenuPrincipal* menuPrincipal;
    MenuFase* menuFase;
    MenuRanking* menuRanking;
    MenuNome* menuNome; 
    EstadoJogo estadoAtual;
    int opcaoMenuPrincipal;
    int opcaoMenuFase;
    int qtdJogadores;
    std::string nomeJogador; 

public:
    Jogo();
    ~Jogo();

    void Executar();
    void setOpcaoMenuPrincipal(int opcao);
    void setOpcaoMenuFase(int opcao);
};