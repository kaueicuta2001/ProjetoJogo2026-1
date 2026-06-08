#include "menu.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Menu::Menu(int id) :
Ente(id),
selecionado(false),
opcaoSelecionada(-1)
{
    opcoesMenu.push_back("Iniciar Jogo");
    opcoesMenu.push_back("Sair");
    InicializaBG();
    InicializaTextos();
}

Menu::~Menu()
{
}

void Menu::InicializaBG()
{
    if (!textura.loadFromFile("../assets/menuBG.png"))
        cerr << "Erro ao carregar a textura de fundo!" << endl;
    sprite.setTexture(textura);
    sprite.setPosition(0.f, 0.f);
    sprite.setScale(
        pGG->getWindow()->getSize().x / textura.getSize().x,
        pGG->getWindow()->getSize().y / textura.getSize().y
    );
}

void Menu::InicializaTextos()
{    
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
    
    for (size_t i = 0; i < opcoesMenu.size(); ++i)
    {
        Text textoLocal;
        textoLocal.setFont(fonte);
        textoLocal.setString(opcoesMenu[i]);
        textoLocal.setCharacterSize(24);
        textoLocal.setFillColor(sf::Color::White);
        textoLocal.setPosition(100.f, 100.f + i * 40.f);
        textosMenu.push_back(textoLocal);
    }
}

// Nova função que recebe o evento mastigado vindo do Jogo.cpp
void Menu::TratarEventos(sf::Event event)
{
    static int opcao = 0; // Mantém o estado do índice do botão

    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::W || event.key.code == Keyboard::Up)
            opcao = (opcao - 1 + opcoesMenu.size()) % opcoesMenu.size();
        
        else if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)
            opcao = (opcao + 1) % opcoesMenu.size();
        
        else if (event.key.code == Keyboard::Enter)
        {
            opcaoSelecionada = opcao + 1; // 1 para iniciar, 2 para sair
            selecionado = true;
        }
    }

    // Atualiza as cores imediatamente quando o evento acontece
    for (size_t i = 0; i < textosMenu.size(); ++i)
    {
        if (i == static_cast<size_t>(opcao))
            textosMenu[i].setFillColor(Color::Yellow);
        else
            textosMenu[i].setFillColor(Color::White);
    }
}

bool Menu::getSelecionado() const
{
    return selecionado;
}

void Menu::setSelecionado(bool sel)
{
    selecionado = sel;
}

int Menu::getOpcaoSelecionada() const
{
    return opcaoSelecionada;
}

void Menu::Executar()
{
    // O Executar agora NÃO tem pollEvent. Ele apenas renderiza o estado atual!
    Desenhar(); 

    for (size_t i = 0; i < textosMenu.size(); ++i)
    {
        pGG->getWindow()->draw(textosMenu[i]);
    }
}