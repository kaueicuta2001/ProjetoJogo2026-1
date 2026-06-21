#pragma once

#include "entidade.h"

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Jogador;
            class ReiBesouro;
        }
    }
}

namespace TheFrog{
    namespace Entidades{
        class Projetil : public Entidade
        {
        private:
            int dano;
            sf::Vector2f direcaoTiro; 
            Personagens::ReiBesouro* pReiBesouro; 
        public:
            Projetil(int id, sf::Vector2f pos, Personagens::ReiBesouro* rei);
            ~Projetil();
                
            void Mover();
            void AumentarDano();
            void AumentarDanoReiBesouro();
            void Danificar(Personagens::Jogador* pJogador);
                
            void Executar();
            void Salvar();
        };
    }
}