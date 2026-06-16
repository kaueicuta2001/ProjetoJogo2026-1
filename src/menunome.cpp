#include "menunome.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"
#include <iostream>

using namespace sf;
using namespace std;

MenuNome::MenuNome(int id, Jogo* jogo) :
Menu(id, jogo),
titulo("Insira o seu Nick (3 Letras)"), // <-- INICIALIZADO CORRETAMENTE AQUI
nomeDigitado("")
{
    InicializaTitulo();
    
    textoNome.setFont(fonte);
    textoNome.setCharacterSize(60);
    textoNome.setFillColor(Color::Yellow);
    textoNome.setPosition(560.f, 350.f);
}

MenuNome::~MenuNome() {}

void MenuNome::InicializaOpcoesMenu() {
    opcoesMenu.push_back("Pressione ENTER para confirmar");
}

void MenuNome::PosicionaBotoes() {
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        botoesMenu[i].setPosition(420.f, 500.f + i * 40.f);
    }
}

void MenuNome::InicializaTitulo() {
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
    textoTitulo.setFont(fonte);
    textoTitulo.setString(titulo);
    textoTitulo.setCharacterSize(40);
    textoTitulo.setFillColor(Color::Green);
    textoTitulo.setPosition(250.f, 150.f);
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
    // Captura as letras nativamente
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
    
    if(nomeDigitado.size() == 3) {
        DesenharBotoes();
    }
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