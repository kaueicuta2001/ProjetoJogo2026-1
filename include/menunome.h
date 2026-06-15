#pragma once
#include "menu.h"
#include <string>

class MenuNome : public Menu {
private:
    std::string titulo; 
    std::string nomeDigitado;
    sf::Text textoNome;
    sf::Text instrucao;

public:
    MenuNome(int id, Jogo* jogo);
    ~MenuNome();

    void InicializaOpcoesMenu() override;
    void PosicionaBotoes() override;
    void InicializaTitulo() override;

    void Notificar(sf::Event evento) override;
    void Executar() override;

    std::string getNomeDigitado() const { return nomeDigitado; }
    void resetNome() { nomeDigitado = ""; selecionado = false; }
};