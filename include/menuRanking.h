#pragma once
#include "menu.h"
#include <string>

class MenuRanking : public Menu {
private:
    std::string titulo; 
    sf::Text textoFiltro;
    int estadoFiltro; 

public:
    MenuRanking(int id, Jogo* jogo);
    ~MenuRanking();

    void InicializaOpcoesMenu() override;
    void PosicionaBotoes() override;
    void InicializaTitulo() override;
    
    void Notificar(sf::Event evento) override; 
    void AtualizarRanking();
    void Executar() override;
};