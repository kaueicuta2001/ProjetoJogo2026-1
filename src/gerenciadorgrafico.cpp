#include "gerenciadorgrafico.h"
#include "entidade.h"

using namespace sf;
using namespace TheFrog::Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGG = nullptr;

GerenciadorGrafico::GerenciadorGrafico() :
window(new RenderWindow(VideoMode({1280, 720}), "The Frog++")),
vsyncAtivo(true)
{
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(vsyncAtivo);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window != nullptr)
    {
        delete window;
    }
    if (pGG != nullptr)
    {
        delete pGG;
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

void GerenciadorGrafico::DesenharEnte(Ente* pEnte)
{
    if(pEnte != nullptr)
    {
        window->draw(pEnte->getSprite());
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

void GerenciadorGrafico::setVsync(bool ativo) 
{
    vsyncAtivo = ativo;
    window->setVerticalSyncEnabled(vsyncAtivo);
}