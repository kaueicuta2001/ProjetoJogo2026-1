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
    sf::Text titulo;
    std::vector<sf::Text> botoesMenu;
public:
    Menu(int id);
    ~Menu();
    void InicializaBG();
    void InicializaTextos();
    void TratarEventos();
    bool getSelecionado() const;
    void setSelecionado(bool sel);
    int getOpcaoSelecionada() const;
    void Executar();
}; 