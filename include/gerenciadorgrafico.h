#pragma once

#include <SFML/Graphics.hpp>

class Entidade;

class GerenciadorGrafico
{
private:
    sf::RenderWindow* window;
    static GerenciadorGrafico* pGG;
    GerenciadorGrafico();

public:
    ~GerenciadorGrafico();
    static GerenciadorGrafico* getGerenciadorGrafico();
    sf::RenderWindow* getWindow();
    void LimpaJanela();
    void DesenharEnte(Ente* pEnte);
    void Renderizar();
    void FecharJanela();
    bool VerificaJanelaAberta() const;
};
