#include "menufase.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace std;
using namespace sf;
using namespace TheFrog::Menus;

MenuFase::MenuFase(TheFrog::Jogo* jogo) :
Menu(jogo)
{
    InicializaOpcoesMenu();
    InicializaBotoes();
    PosicionaBotoes();
    InicializaTextoFase();
}

MenuFase::~MenuFase()
{
    opcoesMenu.clear();
    botoesMenu.clear();
}

void MenuFase::InicializaOpcoesMenu()
{
    opcoesMenu.push_back("Fase 1");
    opcoesMenu.push_back("Fase 2");
    opcoesMenu.push_back("Voltar");
}

void MenuFase::PosicionaBotoes()
{
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        botoesMenu[i].setPosition(525.f, 375.f + i * 40.f);
    }
}

void MenuFase::InicializaTextoFase()
{
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;

    textoFase.setFont(fonte);
    textoFase.setString("Selecione uma fase:");
    textoFase.setCharacterSize(30);
    textoFase.setFillColor(Color::Yellow);
    textoFase.setPosition(435.f, 300.f);
}

void MenuFase::Executar()
{
    Menu::Executar(); 
    if (selecionado) {
        pJog->setOpcaoMenuFase(opcaoSelecionada);
    }
    pGG->getWindow()->draw(textoFase);
}