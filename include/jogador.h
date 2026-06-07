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
    public:
        Jogador(int id, sf::Vector2f pos);
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
