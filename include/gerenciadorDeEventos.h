#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "observador.h"

class GerenciadorGrafico;

class GerenciadorDeEventos {
private:
    std::list<Observador*> observadores;
    static GerenciadorDeEventos* pGE;
    GerenciadorGrafico* pGG;
    bool capturandoInput;

    GerenciadorDeEventos(); 

public:
    ~GerenciadorDeEventos();
    static GerenciadorDeEventos* getGerenciadorDeEventos();

    void Anexar(Observador* obs);
    void Desanexar(Observador* obs);
    void Executar();
};