#pragma once

#include "ente.h"

class Entidade : public Ente
{
    protected:
        int x;
        int y;
    public:
        Entidade(int x, int y, int id);
        virtual ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};
