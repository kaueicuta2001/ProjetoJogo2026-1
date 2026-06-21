#pragma once

#include "inimigo.h"
#include <cmath>

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Jogador;
        }
    }
}

namespace TheFrog{
    namespace Entidades{
        class Projetil;
    }
}

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class ReiBesouro : public Inimigo
            {
            private:
                enum class EstadoIA { Patrulhando, Perseguindo };
                EstadoIA estadoAtual;

                bool maldade;   
                short int forca;
                float raioDeteccao;
                float limiteDir;
                float limiteEsq;
                int direcao;
                bool atirar;
                int tempoTiro;
                int maxTempoTiro;
                sf::Vector2f direcaoTiro;
                Entidades::Projetil* pProjetil;
                Jogador* pJogadorAlvo;
                Jogador* pJogador;
                Jogador* pJogador2;
                void AlterarSpriteMeiaVida();
                void AtualizarEstado();
                void VerificarAtaque();
            public:
                ReiBesouro(int id, sf::Vector2f pos, Jogador* pJogador, Jogador* pJogador2 = nullptr);
                ~ReiBesouro();
                bool getAtirar() const;
                void setProjetil(Entidades::Projetil* proj);
                sf::Vector2f getDirecaoTiro();
                void Mover();
                void AprimorarMaldade();
                void Executar();
                void Salvar();
                void Danificar(Jogador* jogador);
                void ResetAtirar();
            };
        }
    }
}