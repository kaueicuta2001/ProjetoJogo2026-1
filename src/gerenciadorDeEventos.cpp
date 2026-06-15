#include "gerenciadorDeEventos.h"
#include "gerenciadorgrafico.h"

GerenciadorDeEventos* GerenciadorDeEventos::pGE = nullptr;

GerenciadorDeEventos::GerenciadorDeEventos() {
    pGG = GerenciadorGrafico::getGerenciadorGrafico();
}

GerenciadorDeEventos::~GerenciadorDeEventos() {
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
    }
}

void GerenciadorDeEventos::Desanexar(Observador* obs) {
    if (obs) {
        observadores.remove(obs);
    }
}

void GerenciadorDeEventos::Executar() {
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