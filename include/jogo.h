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
    MenuNome* menuNome; // PONTEIRO PARA O NOVO ECRÃ
    EstadoJogo estadoAtual;
    int opcaoMenuPrincipal;
    int opcaoMenuFase;
    int qtdJogadores; // Guarda se foi selecionado 1 ou 2
    std::string nomeJogador; // Guarda o nome do gajo

public:
    Jogo();
    ~Jogo();

    void Executar();
    void setOpcaoMenuPrincipal(int opcao);
    void setOpcaoMenuFase(int opcao);
};