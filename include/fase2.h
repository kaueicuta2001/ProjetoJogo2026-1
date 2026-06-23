#pragma once

#include "fase.h"
#include "cactopulante.h"
#include "ReiBesouro.h"

namespace TheFrog{
    namespace Fases{ 
        class Fase2 : public Fase
        {
            private:
            int maxVespas;
            int maxReiBesouro;
            std::vector<Entidades::Personagens::ReiBesouro*> vReiBesouros;
            public:
            Fase2(Entidades::Personagens::Jogador* pJogador, Entidades::Personagens::Jogador* pJogador2);
            ~Fase2();
            
            void CriarInimigos() override;
            void CriarObstaculos() override;
            
            void CriarReiBesouro();
            void CriarCactosPulantes();
            
            void VerificarAtirarReiBesouro();
            
            void Executar() override;
        };
    }
}