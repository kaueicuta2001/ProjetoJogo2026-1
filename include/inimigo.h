#pragma once

#include "personagem.h"

class Inimigo : public Personagem
{
    protected:
        int nivel_maldade;
    public:
        Inimigo(int nivel_maldade, int num_vidas, int x, int y, int id);
        virtual ~Inimigo();
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
