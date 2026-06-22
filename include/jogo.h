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

namespace TheFrog{
    class Jogo {
    private:
        TheFrog::Gerenciadores::GerenciadorGrafico* GG;
        TheFrog::Gerenciadores::GerenciadorDeEventos* GE;
        TheFrog::Entidades::Personagens::Jogador* pJogador;
        TheFrog::Entidades::Personagens::Jogador* pJogador2;
        TheFrog::Fases::Fase* faseAtual;
        TheFrog::Menus::MenuPrincipal* menuPrincipal;
        TheFrog::Menus::MenuFase* menuFase;
        TheFrog::Menus::MenuRanking* menuRanking;
        TheFrog::Menus::MenuNome* menuNome; 
        EstadoJogo estadoAtual;
        int opcaoMenuPrincipal;
        int opcaoMenuFase;
        int qtdJogadores;
        bool ganhou;
        std::string nomeJogador; 
    public:
        Jogo();
        ~Jogo();
    
        void Executar();
        void setOpcaoMenuPrincipal(int opcao);
        void setOpcaoMenuFase(int opcao);
    };
}