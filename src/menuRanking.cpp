#include "menuranking.h"
#include "jogo.h"
#include "gerenciadordearquivos.h"
#include <iostream>

using namespace sf;
using namespace std;

MenuRanking::MenuRanking(int id, Jogo* jogo) :
Menu(id, jogo),
titulo("Ranking"),
estadoFiltro(0) // Começa no 1 Jogador / Fase 1
{
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
        botoesMenu[i].setPosition(450.f, 300.f + i * 50.f); // Rebaixado para caber o filtro
    }
}

void MenuRanking::InicializaTitulo() {
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
        
    textoTitulo.setFont(fonte);
    textoTitulo.setString(titulo);
    textoTitulo.setCharacterSize(50);
    textoTitulo.setFillColor(Color::Yellow);
    textoTitulo.setPosition(450.f, 80.f);
    
    textoFiltro.setFont(fonte);
    textoFiltro.setCharacterSize(25);
    textoFiltro.setFillColor(Color::Cyan);
    textoFiltro.setPosition(380.f, 200.f);
}

void MenuRanking::Notificar(sf::Event evento) {
    Menu::Notificar(evento); // Mantém Enter, Esc, Up, Down funcionando
    
    if (!ativo) return;

    // Adiciona a leitura das setas Esquerda e Direita (ou A e D) para trocar a aba
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