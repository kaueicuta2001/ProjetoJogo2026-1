#pragma once

#include <SFML/Graphics.hpp>
#include "ente.h"

class GerenciadorGrafico
{
private:
    RenderWindow window;
    RectangleShape retangulogenerico;

public:
    GerenciadorGrafico() : window(VideoMode(800, 600), "Janela do Game")
    {
        window.setFramerateLimit(60);
    }
    ~GerenciadorGrafico() {}

    void desenharEnte(Ente* pE);

    void moverretangulo(Vector2f moverrr)
    {
        retangulogenerico.move(moverrr);
    }

    bool janelaAberta()
    {
        return window.isOpen();
    }

    void janelaClear()
    {
        window.clear(Color::Blue);
    }

    void janelaDisplay()
    {
        window.display();
    }

    void fechaJanela()
    {
        window.close();
    }

    void gerenciarEventos(Event& evento)
    {
        while (window.pollEvent(evento))
        {
            if (evento.type == Event::Closed)
            {
                window.close();
            }
        }
    }
};