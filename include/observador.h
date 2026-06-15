#pragma once
#include <SFML/Graphics.hpp>

class Observador {
public:
    Observador() {}
    virtual ~Observador() {}
    
    virtual void Notificar(sf::Event evento) = 0;
};