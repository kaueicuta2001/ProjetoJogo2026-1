#include "menuprincipal.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace std;
using namespace sf;
using namespace TheFrog::Menus;

MenuPrincipal::MenuPrincipal(int id, Jogo* jogo) :
Menu(id, jogo),
titulo("The Frog ++")
{
    InicializaOpcoesMenu();
    InicializaBotoes();
    PosicionaBotoes();
    InicializaTitulo();
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

void MenuPrincipal::PosicionaBotoes()
{
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        botoesMenu[i].setPosition(525.f, 375.f + i * 40.f);
    }
}

void MenuPrincipal::InicializaTitulo()
{
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;

    textoTitulo.setFont(fonte);
    textoTitulo.setString(titulo);
    textoTitulo.setCharacterSize(50);
    textoTitulo.setFillColor(Color::Green);
    textoTitulo.setPosition(375.f, 150.f);
}

void MenuPrincipal::Executar()
{
    Menu::Executar(); 
    if (selecionado) {
        pJog->setOpcaoMenuPrincipal(opcaoSelecionada);
    }
}