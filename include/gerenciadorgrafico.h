#pragma once

#include <SFML/Graphics.hpp>
#include "ente.h"

class GerenciadorGrafico
{
private:
    sf::RenderWindow window;

    static GerenciadorGrafico* pGG;
    GerenciadorGrafico();

public:
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    static GerenciadorGrafico* getGerenciadorGrafico();
    sf::RenderWindow* getWindow();
    void LimpaJanela();
    void DesenhaElemento(sf::RectangleShape corpo);
    void MostraElemento();
    void FecharJanela();
    const bool VerificaJanelaAberta();
};