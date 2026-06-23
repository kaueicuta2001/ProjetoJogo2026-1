#include "menunome.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;
using namespace TheFrog::Menus;

MenuNome::MenuNome(TheFrog::Jogo* jogo) :
Menu(jogo),
nomeDigitado("")
{
    titulo = "Insira o seu Nick (3 Letras)";
    
    InicializaTitulo();

    textoTitulo.setPosition(250.f, 150.f);
    textoNome.setFont(fonte);
    textoNome.setCharacterSize(60);
    textoNome.setFillColor(Color::Yellow);
    textoNome.setPosition(560.f, 350.f);

    InicializaOpcoesMenu();
    InicializaBotoes();
    PosicionaBotoes();
}

MenuNome::~MenuNome() {}

void MenuNome::InicializaOpcoesMenu() {
    opcoesMenu.push_back("Digite seu nome (3 letras) e pressione Enter");
    
}

void MenuNome::PosicionaBotoes() {
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        botoesMenu[i].setPosition(250.f, 600.f + i * 40.f);
    }
}

void MenuNome::Notificar(sf::Event evento) {
    if (!ativo) return;

    if (evento.type == Event::KeyPressed) {
        if(evento.key.code == Keyboard::Escape) {
            pGG->getWindow()->close();
        }
        else if (evento.key.code == Keyboard::Backspace) {
            if (!nomeDigitado.empty())
            {
                nomeDigitado.pop_back();
            }
        }
        else if (evento.key.code == Keyboard::Enter) {
            if (nomeDigitado.size() == 3) {
                selecionado = true;
            }
        }
    }
    else if (evento.type == Event::TextEntered) {
        if (evento.text.unicode >= 65 && evento.text.unicode <= 90 && nomeDigitado.size() < 3) {
            nomeDigitado += static_cast<char>(evento.text.unicode);
        }
        else if (evento.text.unicode >= 97 && evento.text.unicode <= 122 && nomeDigitado.size() < 3) {
            nomeDigitado += static_cast<char>(evento.text.unicode - 32); // Converte para Maiúsculas
        }
    }
}

void MenuNome::Executar() {
    Menu::Executar();
    textoNome.setString(nomeDigitado + "_"); // Efeito de cursor a piscar
    pGG->getWindow()->draw(textoNome);
    
    DesenharBotoes();
}

string MenuNome::getNomeDigitado() const
{
    return nomeDigitado;
}

void MenuNome::resetNome()
{
    nomeDigitado = "";
    selecionado = false;
}