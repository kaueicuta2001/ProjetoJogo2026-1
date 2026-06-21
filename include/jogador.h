#pragma once
#include "personagem.h"
#include "inimigo.h"

namespace TheFrog{
    namespace Entidades{
        namespace Personagens{
            class Jogador : public Personagem
            {
                private:
                int pontos;
                bool imune;
                int tempoImune;
                int maxTempoImune;
                bool jogador2;
                float velOriginal;
                
                public:
                Jogador(int id, sf::Vector2f pos, bool isJogador2 = false);
                ~Jogador();
                
                void Mover() override;
                void Pular();
                void resetVelX();
                
                void Pisar(Inimigo* inimigo);
                
                void Executar() override;
                void Salvar() override;
                
                int getVidas() const;
                bool getImune() const;
                void IniciarImunidade();
                void AtualizarImunidade();
                void setVelY(float vY);
                float getVelX() const;
                void setVelX(float vX);
                int getPontos() const; // NOVO: Retorna os pontos para salvar
            };
        }
    }
}
