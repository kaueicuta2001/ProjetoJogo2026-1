#pragma once

#include "jogador.h"
#include "besouro.h"
#include "plataforma.h"
#include "chao.h"
#include "listaentidades.h"
#include "gerenciadorDeColisoes.h"
#include "observador.h"

#include <iostream>
#include <string>
#include <vector>
#include <SFML/System.hpp>

namespace TheFrog{
    namespace Fases{
        class Fase : public TheFrog::Ente, public Observador
        {
            protected:
            Listas::ListaEntidades listaEntidades;
            Gerenciadores::GerenciadorDeColisoes gerenciadorColisoes;
            Entidades::Personagens::Jogador* pJogador;
            Entidades::Personagens::Jogador* pJogador2;
            float barraLargura;
            float barraAltura;
            float margem;
            sf::RectangleShape fundoBarraj1;
            sf::RectangleShape barraVidaj1;
            sf::RectangleShape fundoBarraj2;
            sf::RectangleShape barraVidaj2;
            sf::Font fonteVida;
            sf::Text textoVidaJ1;
            sf::Text textoVidaJ2;
            int maxBesouros;
            int maxPlataformas;
            int maxObstDificil;
            bool faseAtiva;
            bool ganhou;
            sf::Clock relogioFase;
            
            public:
            Fase(Entidades::Personagens::Jogador* jogador, Entidades::Personagens::Jogador* jogador2);
            virtual ~Fase();
            
            void CriarCenario();
            virtual void CriarInimigos() = 0;
            virtual void CriarObstaculos() = 0;
            
            void CriarBesouros();
            void CriarPlataformas();
            void CriarChao();
            void InicializarBarrasDeVida();
            void AtualizarBarrasDeVida();
            void DesenharBarrasDeVida();
            
            virtual void Executar();
            void VerificarEstadoFase();
            int ContarInimigosVivos();
            
            void Notificar(sf::Event evento) override; 
            
            bool getFaseAtiva() const;
            int getTempoJogado() const; 
            bool getGanhou() const;
        };
    }
}