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
        static void setGG(GerenciadorGrafico* gg);
        virtual ~Ente();
        virtual void Executar() = 0;
        //void desenhar() {}
};