#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ente.h"

class Jogo;

class Menu : public Ente
{
protected:
    int opcaoIndice;
    int opcaoSelecionada;
    bool selecionado;
    Jogo* pJog;
    sf::Event event;
    std::vector<std::string> opcoesMenu;
    sf::Font fonte;
    std::vector<sf::Text> botoesMenu;
public:
    Menu(int id, Jogo* jogo);
    virtual ~Menu();
    void InicializaBG();
    virtual void InicializaOpcoesMenu() = 0;
    void InicializaBotoes();
    virtual void PosicionaBotoes() = 0;
    void NavegarOpcao();
    void DesenharBotoes();
    bool getSelecionado() const;
    virtual void Executar() = 0;
}; 