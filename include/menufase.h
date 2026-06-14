#pragma once

#include "menu.h"

class MenuFase : public Menu
{
private:
    std::string titulo;
    sf::Text textoTitulo;
public:
    MenuFase(int id, Jogo* jogo);
    ~MenuFase();
    void InicializaOpcoesMenu();
    void InicializaTitulo();
    void PosicionaBotoes();
    void DesenharTitulo();
    void Executar();
};