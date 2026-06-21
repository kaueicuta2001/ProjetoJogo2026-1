#pragma once
#include "obstaculo.h"

namespace TheFrog{
    namespace Entidades{
        namespace Personagens
        {
            class Jogador;
        }
    }
}

namespace TheFrog{
    namespace Entidades{
        namespace Obstaculos{
            class CactoPulante : public Obstaculo {
            private:
                short int danosidade;
                bool espinhosFlamejantes; 
                int vidaJogador;
            public:
                CactoPulante(int id, sf::Vector2f pos);
                ~CactoPulante();

                void FlamejarEspinhos();
                void Obstaculizar(Personagens::Jogador* pJogador);
                void Danificar(Personagens::Jogador* pJogador);
                void Executar() override;
                void Salvar() override;
            };
        }
    }
}