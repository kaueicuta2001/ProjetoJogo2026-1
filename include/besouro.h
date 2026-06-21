#pragma once

#include "inimigo.h"

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Jogador;
        }
    }
}

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Besouro : public Inimigo
            {
            private:
                float distancia;
                float limiteDir;
                float limiteEsq;
                int direcao;
                bool antenasVenenosas;
                void AtivarAntenaVenenosa();
                void AlterarSpriteMeiaVida();
            public:
                Besouro(int id, sf::Vector2f pos, float dist);
                ~Besouro();
                void Mover();
                void AprimorarMaldade();
                void Danificar(Jogador* jogador);
                void Executar();
                void Salvar();
            };
        }
    }
}