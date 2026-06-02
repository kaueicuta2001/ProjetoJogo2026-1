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
    void DesenhaSprite(sf::Sprite* pSprite);
    void Renderizar();
    void FecharJanela();
    bool VerificaJanelaAberta() const;
};
