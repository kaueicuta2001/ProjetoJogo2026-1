#pragma once

#include <iostream>

#include "gerenciadorgrafico.h"

class Ente
{
    protected:
        int id;
        static GerenciadorGrafico* pGG;
    public:
        Ente(int id);
        virtual ~Ente();
        static void setGG(GerenciadorGrafico* gg);
        virtual void Executar() = 0;
        //void desenhar() {}
};