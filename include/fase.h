#pragma once
#include "ente.h"
#include "jogador.h"
#include "listaentidades.h"
#include "gerenciadorDeColisoes.h"
#include "observador.h"
#include <SFML/System.hpp> 

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
    Fase(int id, Jogador* jogador, Jogador* jogador2 = nullptr);
    virtual ~Fase();

    void CriarCenario();
    void CriarInimigos();
    void CriarObstaculos();

    void CriarBesouros();
    void CriarPlataformas();

    virtual void Executar();
    bool VerificarEstadoFase();
    int ContarInimigosVivos();

    void Notificar(sf::Event evento) override; 
    
    bool getFaseAtiva() const;
    int getTempoJogado() const; 
};