#include "gerenciadorDeEventos.h"
#include "gerenciadorgrafico.h"

GerenciadorDeEventos* GerenciadorDeEventos::pGE = nullptr;

GerenciadorDeEventos::GerenciadorDeEventos() :
capturandoInput(true)
{
    pGG = GerenciadorGrafico::getGerenciadorGrafico();
}

GerenciadorDeEventos::~GerenciadorDeEventos() {
    capturandoInput = false;
    observadores.clear();
}

GerenciadorDeEventos* GerenciadorDeEventos::getGerenciadorDeEventos() {
    if (pGE == nullptr) {
        pGE = new GerenciadorDeEventos();
    }
    return pGE;
}

void GerenciadorDeEventos::Anexar(Observador* obs) {
    if (obs) {
        observadores.push_back(obs);
        obs->seEstaObservando(true);
        capturandoInput = true;
    }
}

void GerenciadorDeEventos::Desanexar(Observador* obs) {
    if (obs) {
        observadores.remove(obs);
        obs->seEstaObservando(false);
        capturandoInput = false;
    }
}

void GerenciadorDeEventos::Executar() {
    if(!capturandoInput) return;
    sf::Event evento;
    while (pGG->getWindow()->pollEvent(evento)) {
        
        if (evento.type == sf::Event::Closed) {
            pGG->FecharJanela();
        }

        for (auto obs : observadores) {
            obs->Notificar(evento);
        }
    }
}