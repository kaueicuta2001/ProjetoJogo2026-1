#pragma once

#include "fase.h"
#include "vespa.h"
#include "lamalento.h"

namespace TheFrog{
    namespace Fases{
        class Fase1 : public Fase
        {
            private:
            int maxVespas;
            int maxLamalentos;
            public:
            Fase1(int id, Entidades::Personagens::Jogador* pJogador = nullptr, Entidades::Personagens::Jogador* pJogador2 = nullptr);
            ~Fase1();
            
            void CriarInimigos();
            void CriarObstaculos();
            
            void CriarVespas();
            void CriarLamasLentas();
            
            void Executar() override;
        };
    }
}