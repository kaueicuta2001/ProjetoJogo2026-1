#pragma once

#include <SFML/Graphics.hpp>

class Entidade;

class GerenciadorGrafico
{
private:
    sf::RenderWindow* window;
    sf::RectangleShape corpoGenerico;
    static GerenciadorGrafico* pGG;
    GerenciadorGrafico();

public:
    ~GerenciadorGrafico();
    static GerenciadorGrafico* getGerenciadorGrafico();
    sf::RenderWindow* getWindow();
    void LimpaJanela();
    void DesenhaElemento(Entidade* pEntidade);
    void Renderizar();
    void FecharJanela();
    bool VerificaJanelaAberta() const;
};
