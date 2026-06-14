#pragma once

#include "personagem.h"
#include "inimigo.h"

class Jogador : public Personagem
{
    private:
        int pontos;
        bool imune;
        int tempoImune;
        int maxTempoImune;
        const bool jogador2;
    public:
        Jogador(int id, sf::Vector2f pos, bool isJogador2);
        ~Jogador();
        void Mover();
        void Pular();
        void setVelY(float velY);
        void Pisar(Inimigo* inimigo);
        int getVidas() const;
        bool getImune() const;
        void IniciarImunidade();
        void AtualizarImunidade();
        void Executar();
        void Salvar();
};
