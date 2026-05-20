#pragma once

#include "Inimigo.h"

class InimigoMedio : public Inimigo
{
    private:
        int tamanho;
    public:
        InimigoMedio(int tamanho, int nivel_maldade, int num_vidas, int x, int y, int id);
        ~InimigoMedio();
        void Executar();
        void Salvar();
};