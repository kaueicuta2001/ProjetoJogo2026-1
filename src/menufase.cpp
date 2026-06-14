#include "menufase.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

MenuFase::MenuFase(int id, Jogo* jogo) :
Menu(id, jogo),
titulo("The Frog ++")
{
    InicializaOpcoesMenu();
    InicializaBotoes();
    PosicionaBotoes();
    InicializaTitulo();
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

void MenuFase::InicializaTitulo()
{
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
    std::cerr << "Erro ao carregar a fonte!" << std::endl;

    textoTitulo.setFont(fonte);
    textoTitulo.setString(titulo);
    textoTitulo.setCharacterSize(48);
    textoTitulo.setFillColor(sf::Color::White);
    textoTitulo.setPosition(400.f, 200.f);
}

void MenuFase::DesenharTitulo()
{
    pGG->getWindow()->draw(textoTitulo);
}

void MenuFase::Executar()
{
    Desenhar();
    DesenharTitulo();

    NavegarOpcao();
    if (selecionado)
    {
        pJog->setOpcaoMenuFase(opcaoSelecionada);
    }
    DesenharBotoes();
}