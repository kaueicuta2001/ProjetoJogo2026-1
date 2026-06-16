#pragma once
#include "entidade.h"
#include <string>

class Personagem : public Entidade
{
    protected:
        int num_vidas;
        int dano;
        
    public:
        Personagem(int id, sf::Vector2f pos);
        ~Personagem();
        
        virtual void Mover() = 0;
        void PerderVidas(int danos);
        int getVidas() const;
        int getDano() const;
        
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};