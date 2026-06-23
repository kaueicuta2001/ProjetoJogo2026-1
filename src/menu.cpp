#include "menu.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeEventos.h"
#include <iostream>

using namespace std;
using namespace sf;
using namespace TheFrog::Menus;
using namespace TheFrog::Gerenciadores;
using namespace TheFrog::Entidades::Personagens;

Menu::Menu(Jogo* jogo) :
opcaoIndice(0),
opcaoSelecionada(-1),
selecionado(false),
ativo(false),
titulo("The Frog ++"),
pJog(jogo)
{
    InicializaBG();
    InicializaTitulo();
    GerenciadorDeEventos::getGerenciadorDeEventos()->Anexar(this); 
}    

Menu::~Menu()
{
    GerenciadorDeEventos::getGerenciadorDeEventos()->Desanexar(this);
}    

void Menu::InicializaBG()
{
    if (!textura.loadFromFile("../assets/menuBG.png"))
        cerr << "Erro ao carregar a textura de fundo!" << endl;
    sprite.setTexture(textura);    
    sprite.setPosition(posicao);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );    
}    

void Menu::InicializaTitulo()
{
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;

    textoTitulo.setFont(fonte);
    textoTitulo.setString(titulo);
    textoTitulo.setCharacterSize(50);
    textoTitulo.setFillColor(Color::Green);
    textoTitulo.setPosition(400.f, 150.f);
}


void Menu::InicializaBotoes()
{    
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
        
    for (size_t i = 0; i < opcoesMenu.size(); ++i)
    {
        Text textoLocal;
        textoLocal.setFont(fonte);
        textoLocal.setString(opcoesMenu[i]);
        textoLocal.setCharacterSize(30);
        textoLocal.setFillColor(Color::White);
        botoesMenu.push_back(textoLocal);
    }    
}    

void Menu::Notificar(sf::Event evento)
{
    if (!ativo) return;

    if (evento.type == Event::KeyPressed)
    {
        if(evento.key.code == Keyboard::Escape)
        {
            pGG->getWindow()->close();
        }
        else if (evento.key.code == Keyboard::W || evento.key.code == Keyboard::Up){
            opcaoIndice = (opcaoIndice - 1 + opcoesMenu.size()) % opcoesMenu.size();
        }
        else if (evento.key.code == Keyboard::S || evento.key.code == Keyboard::Down){
            opcaoIndice = (opcaoIndice + 1) % opcoesMenu.size();
        }
        else if (evento.key.code == Keyboard::Enter)
        {
            opcaoSelecionada = opcaoIndice;
            selecionado = true;
        }
    }
}

void Menu::DesenharBotoes()
{
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        if (i == static_cast<size_t>(opcaoIndice))
            botoesMenu[i].setFillColor(Color::Red);
        else
            botoesMenu[i].setFillColor(Color::White);

        pGG->getWindow()->draw(botoesMenu[i]);
    }
}

void Menu::Executar()
{
    Desenhar();
    pGG->getWindow()->draw(textoTitulo);
    DesenharBotoes();
}

int Menu::getOpcaoSelecionada() const
{
    return opcaoSelecionada;
}

bool Menu::getSelecionado() const
{
    return selecionado;
}

void Menu::resetSelecionado()
{
    selecionado = false;
}

void Menu::setAtivo(bool estado)
{
    ativo = estado;
}