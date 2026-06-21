#pragma once

#include "jogador.h"
#include "inimigo.h"
#include "obstaculo.h"
#include "chao.h"
#include "projetil.h"
#include <list>

namespace TheFrog{
    namespace Gerenciadores{
        class GerenciadorDeColisoes {
            private:
            sf::Vector2f intersecao;
            Entidades::Personagens::Jogador* pJogador;
            Entidades::Personagens::Jogador* pJogador2;
            std::list<Entidades::Personagens::Inimigo*> listaInimigos;
            std::list<Entidades::Obstaculos::Obstaculo*> listaObstaculos;
            std::list<Entidades::Chao*> listaChao;
            std::list<Entidades::Projetil*> listaProjeteis;
            int totalColisoes;
            public:
            
            GerenciadorDeColisoes(Entidades::Personagens::Jogador* pJ = nullptr, Entidades::Personagens::Jogador* pJ2 = nullptr);
            ~GerenciadorDeColisoes();
            
            void getTotalColisoes() const;    
            void IncluirInimigo(Entidades::Personagens::Inimigo* pI);
            void IncluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
            void IncluirChao(Entidades::Chao* pC);
            void IncluirProjetil(Entidades::Projetil* pP);
            
            bool VerificarColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
            
            void TratarColisoesPersChao();
            void TratarColisoesJogsObstacs();
            void TratarColisoesJogsInimgs();
            void TratarColisoesJogsProjeis();
            void TratarColisoesInimgsObstacs();
            
            void Executar();
            
            void RemoverInimigoInativo();
            void RemoverObstaculoInativo();
            void RemoverProjetilInativo();
        };
    }
}
