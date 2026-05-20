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
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
