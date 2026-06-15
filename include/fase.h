#pragma once
#include "ente.h"
#include "jogador.h"
#include "listaentidades.h"
#include "gerenciadorDeColisoes.h"
#include "observador.h"
#include <SFML/System.hpp> // <-- Necessário para o sf::Clock

class Fase : public Ente, public Observador
{
protected:
    ListaEntidades listaEntidades;
    GerenciadorDeColisoes gerenciadorColisoes;
    Jogador* pJogador;
    Jogador* pJogador2;
    int maxBesouros;
    int maxPlataformas;
    int maxObstDificil;
    bool faseAtiva;
    sf::Clock relogioFase; // <-- RELÓGIO ADICIONADO AQUI

public:
    Fase(int id, Jogador* jogador = nullptr, Jogador* jogador2 = nullptr);
    virtual ~Fase();

    virtual void CriarCenario() = 0;
    virtual void CriarInimigos() = 0;
    virtual void CriarObstaculos() = 0;

    void CriarBesouros();
    void CriarPlataformas();
    void CriarObstDificil();

    void Executar() override;
    bool VerificarEstadoFase();
    int ContarInimigosVivos();

    void Notificar(sf::Event evento) override; 
    
    bool getFaseAtiva() const { return faseAtiva; } 
    int getTempoJogado() const; 
};