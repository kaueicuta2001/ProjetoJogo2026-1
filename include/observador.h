#pragma once
#include <SFML/Graphics.hpp>

class Observador {
protected:
    bool estaObservando;

public:
    Observador() :
    estaObservando(false) {}

    virtual ~Observador() {}

    void seEstaObservando(bool observando)
    {
        estaObservando = observando;
    }
    
    virtual void Notificar(sf::Event evento) = 0;
};