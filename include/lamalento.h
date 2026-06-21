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
            class LamaLento : public Obstaculo
            {
                private:
                float lentidao;
                int vidasJogador;
                public:
                LamaLento(int id, sf::Vector2f pos);
                ~LamaLento();
                void LentificarJogador(Personagens::Jogador* pJogador);
                void Obstaculizar(Personagens::Jogador* pJogador);
                void Executar();
                void Salvar();
            };
        }
    }
}
