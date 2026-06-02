#pragma once

#include "inimigo.h"

class InimigoMedio : public Inimigo
{
    private:
        float distancia;
        float limiteDir;
        float limiteEsq;
        int direcao;
    public:
        InimigoMedio(int id, sf::Vector2f pos, float dist);
        ~InimigoMedio();
        void Mover();
        void Executar();
        void Salvar();
};
