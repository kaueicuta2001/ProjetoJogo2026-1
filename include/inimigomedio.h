#pragma once

#include "Inimigo.h"

class InimigoMedio : public Inimigo
{
    private:
        int tamanho;
    public:
        InimigoMedio(int id, sf::Vector2f pos, int tamanho, int nivel_maldade, int num_vidas);
        ~InimigoMedio();
        void Mover();
        void Executar();
        void Salvar();
};