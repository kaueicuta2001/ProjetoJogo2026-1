#pragma once

#include <iostream>

#include "gerenciadorgrafico.h"

class Ente
{
    protected:
        int id;
    public:
        Ente(int id);
        virtual ~Ente();
        virtual void Executar() = 0;
        //void desenhar() {}
};