#include "ente.h"
#include "entidade.h"

#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

GerenciadorGrafico::GerenciadorGrafico() :
window(new RenderWindow(VideoMode(800, 600), "Projeto Jogo")),
corpoGenerico(Vector2f(0.f, 0.f))
{
    window->setFramerateLimit(60);
}

GerenciadorGrafico* GerenciadorGrafico::pGG = nullptr;

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window != nullptr)
    delete window;
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGG == nullptr)
        pGG = new GerenciadorGrafico();
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

void GerenciadorGrafico::DesenhaElemento(Entidade*pEntidade)
{
    corpoGenerico.setPosition(pEntidade->getPosicao());
    corpoGenerico.setSize(pEntidade->getTamanho());
    corpoGenerico.setFillColor(pEntidade->getCor());
    window->draw(corpoGenerico);
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