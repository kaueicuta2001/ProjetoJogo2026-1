#include "menuranking.h"
#include "jogo.h"
#include "gerenciadordearquivos.h"
#include <iostream>

using namespace sf;
using namespace std;
using namespace TheFrog::Menus;
using namespace TheFrog::Gerenciadores;

MenuRanking::MenuRanking(TheFrog::Jogo* jogo) :
Menu(jogo),
estadoFiltro(0) 
{
    titulo = "Ranking";
    InicializaTitulo();
    AtualizarRanking(); 
}

MenuRanking::~MenuRanking() {
    opcoesMenu.clear();
    botoesMenu.clear();
}

void MenuRanking::AtualizarRanking() {
    opcoesMenu.clear();
    botoesMenu.clear();
    
    // Decodifica o estadoFiltro (0 a 3)
    int qtdJogadores = (estadoFiltro % 2 == 0) ? 1 : 2;
    int fase = (estadoFiltro < 2) ? 1 : 2;
    
    string strJogadores = (qtdJogadores == 1) ? "1 Jogador" : "2 Jogadores";
    textoFiltro.setString("<  " + strJogadores + " - Fase " + to_string(fase) + "  >");
    
    vector<string> top5 = GerenciadorDeArquivos::LerRanking(qtdJogadores, fase);
    for(const string& linha : top5) {
        opcoesMenu.push_back(linha);
    }
    opcoesMenu.push_back("Voltar"); 
    
    InicializaBotoes();
    PosicionaBotoes();
    opcaoIndice = opcoesMenu.size() - 1; 
}

void MenuRanking::InicializaOpcoesMenu() {}

void MenuRanking::PosicionaBotoes() {
    for (size_t i = 0; i < botoesMenu.size(); ++i) {
        botoesMenu[i].setPosition(450.f, 300.f + i * 50.f);
    }
}

void MenuRanking::Notificar(sf::Event evento) {
    Menu::Notificar(evento); 
    
    if (!ativo) return;

    if (evento.type == Event::KeyPressed) {
        if (evento.key.code == Keyboard::Left || evento.key.code == Keyboard::A) {
            estadoFiltro = (estadoFiltro - 1 + 4) % 4; // Cicla para trás
            AtualizarRanking();
        }
        else if (evento.key.code == Keyboard::Right || evento.key.code == Keyboard::D) {
            estadoFiltro = (estadoFiltro + 1) % 4; // Cicla para frente
            AtualizarRanking();
        }
    }
}

void MenuRanking::Executar() {
    Menu::Executar();
    pGG->getWindow()->draw(textoFiltro); // Desenha a aba atual
    
    if (selecionado) {
        if (opcaoSelecionada == static_cast<int>(opcoesMenu.size() - 1)) {
            pJog->setOpcaoMenuPrincipal(-2); 
        }
        resetSelecionado();
    }
}