#include "menuprincipal.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace std;
using namespace sf;
using namespace TheFrog::Menus;

MenuPrincipal::MenuPrincipal(TheFrog::Jogo* jogo) :
Menu(jogo)
{
    titulo = "The Frog ++";

    InicializaOpcoesMenu();
    InicializaBotoes();
    PosicionaBotoes();
    InicializaTextoSelecione();
}

MenuPrincipal::~MenuPrincipal()
{
    opcoesMenu.clear();
    botoesMenu.clear();
}

void MenuPrincipal::InicializaOpcoesMenu()
{
    opcoesMenu.push_back("1 Jogador");   
    opcoesMenu.push_back("2 Jogadores");
    opcoesMenu.push_back("Ranking");
    opcoesMenu.push_back("Sair");
}

void MenuPrincipal::InicializaTextoSelecione()
{
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;

    textoSelecione.setFont(fonte);
    textoSelecione.setString("Selecione uma opcao:");
    textoSelecione.setCharacterSize(30);
    textoSelecione.setFillColor(Color::Yellow);
    textoSelecione.setPosition(400.f, 300.f);
}

void MenuPrincipal::PosicionaBotoes()
{
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        botoesMenu[i].setPosition(525.f, 375.f + i * 40.f);
    }
}

void MenuPrincipal::Executar()
{
    Menu::Executar(); 
    if (selecionado) {
        pJog->setOpcaoMenuPrincipal(opcaoSelecionada);
    }
    pGG->getWindow()->draw(textoSelecione);
}