#pragma once

#include "entidade.h"

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
            class Obstaculo : public Entidade
            {
                protected:
                bool danoso;
                bool colideInimigo;
                public:
                Obstaculo(int id, sf::Vector2f pos);
                ~Obstaculo();
                
                bool getDanoso() const;
                bool getColide() const;
                virtual void Obstaculizar(Personagens::Jogador* pJogador) = 0;
                virtual void Executar() = 0;
                virtual void Salvar() = 0;
            };
        }
    }
}
