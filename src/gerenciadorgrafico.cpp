#include "gerenciadorgrafico.h"
#include "entidade.h"

using namespace sf;

GerenciadorGrafico* GerenciadorGrafico::pGG = nullptr;

GerenciadorGrafico::GerenciadorGrafico() :
window(new RenderWindow(VideoMode({1280, 720}), "Projeto Jogo"))
{
    window->setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window != nullptr)
    {
        delete window;
    }
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGG == nullptr)
    {
        pGG = new GerenciadorGrafico();
    }
    return pGG;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::LimpaJanela()
{
    window->clear();
}

void GerenciadorGrafico::DesenharEnte(sf::Sprite* pSprite)
{
    if(pSprite != nullptr)
    {
        window->draw(*pSprite);
    }
}

void GerenciadorGrafico::Renderizar()
{
    window->display();
}

void GerenciadorGrafico::FecharJanela()
{
    window->close();
}

bool GerenciadorGrafico::VerificaJanelaAberta() const
{
    return window->isOpen();
}