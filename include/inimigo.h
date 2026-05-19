#pragma once

#include "personagem.h"

class Inimigo : public Personagem
{
    protected:
        int nivel_maldade;
    public:
        Inimigo(int nivel_maldade, int num_vidas, int x, int y, int id) : Personagem(num_vidas, x, y, id), nivel_maldade(nivel_maldade);
        virtual ~Inimigo();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};
