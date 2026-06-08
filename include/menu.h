#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ente.h"

class Jogo;

class Menu : public Ente
{
private:
    int opcao;
    int opcaoSelecionada;
    bool selecionado;
    std::vector<std::string> opcoesMenu;
    sf::Font fonte;
    sf::Text texto;
    std::vector<sf::Text> textosMenu;
public:
    Menu(int id);
    ~Menu();
    void InicializaBG();
    void InicializaTextos();
    void TratarEventos(sf::Event event);
    bool getSelecionado() const;
    void setSelecionado(bool sel);
    int getOpcaoSelecionada() const;
    void Executar();
}; 