#pragma once

#include "obstaculo.h"

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Jogador;
        }
    }
}

namespace TheFrog{
    namespace Entidades{
        namespace Obstaculos{
            class Plataforma : public Obstaculo
            {
                private:
                int tempo;
                public:
                Plataforma(int id, sf::Vector2f pos);
                ~Plataforma();
                
                void DeslizarJogador(Personagens::Jogador* pJogador);
                void Obstaculizar(Personagens::Jogador* pJogador);
                void Executar();
                void Salvar();
            };
        }
    }
}