#pragma once

#include "inimigo.h"

class InimigoMedio : public Inimigo
{
    private:
        int tamanho;
    public:
        InimigoMedio(int id, sf::Vector2f pos);
        ~InimigoMedio();
        void Mover();
        void Executar();
        void Salvar();
};
