#pragma once

#include "entidade.h"

class Personagem : public Entidade
{
    protected:
        int num_vidas;
    public:
        Personagem(int num_vidas, int x, int y, int id);
        ~Personagem();
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
