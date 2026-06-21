#pragma once

#include <SFML/Graphics.hpp>
class Ente;
class Entidade;

class GerenciadorGrafico
{
private:
    sf::RenderWindow* window;
    static GerenciadorGrafico* pGG;
    bool vsyncAtivo;
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
    void setVsync(bool ativo);
};
