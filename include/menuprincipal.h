#pragma once

#include "menu.h"

class MenuPrincipal : public Menu
{
private:
    std::string titulo;
    sf::Text textoTitulo;
public:
    MenuPrincipal(int id, Jogo* jogo);
    ~MenuPrincipal();
    void InicializaOpcoesMenu();
    void InicializaTitulo();
    void PosicionaBotoes();
    void DesenharTitulo();
    void Executar();
};