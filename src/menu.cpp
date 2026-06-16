#include "menu.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include "gerenciadorDeEventos.h"
#include <iostream>

using namespace std;
using namespace sf;

Menu::Menu(int id, Jogo* jogo) :
Ente(id),
opcaoIndice(0),
opcaoSelecionada(-1),
selecionado(false),
ativo(false), // Começa desativado por padrão
pJog(jogo)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    posicao = Vector2f(0.f, 0.f);
    InicializaBG();
    
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
    if (!ativo) return; // BLOQUEIA O TECLADO SE O MENU NÃO ESTIVER NA TELA

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