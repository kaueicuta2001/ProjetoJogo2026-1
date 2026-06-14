#include "menuprincipal.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

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
    opcoesMenu.push_back("Jogador 1");
    opcoesMenu.push_back("Jogador 2");
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
    textoTitulo.setCharacterSize(48);
    textoTitulo.setFillColor(sf::Color::White);
    textoTitulo.setPosition(400.f, 200.f);
}

void MenuPrincipal::DesenharTitulo()
{
    pGG->getWindow()->draw(textoTitulo);
}

void MenuPrincipal::Executar()
{
    Desenhar();
    DesenharTitulo();

    NavegarOpcao();
    if (selecionado)
    {
        pJog->setOpcaoMenuPrincipal(opcaoSelecionada);
    }
    DesenharBotoes();
}