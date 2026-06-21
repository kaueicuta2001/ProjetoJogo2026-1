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
            class Vespa : public Inimigo
            {
            private:
                float angulo;             
                float velocidadeAngular;  
                float amplitudeX;         
                float amplitudeY;         
                sf::Vector2f posInicial;  
                bool glândulasVenenosas;
                void AtivarGlândulaVenenosa();
                void AlterarSpriteMeiaVida();
            public:
                Vespa(int id, sf::Vector2f pos, float dist);
                ~Vespa();
                void Mover();
                void AprimorarMaldade();
                void Danificar(Jogador* pJogador);
                void Executar();
                void Salvar();
            };
        }
    }
}
