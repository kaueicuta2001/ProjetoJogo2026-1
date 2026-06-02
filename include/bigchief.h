#pragma once

#include "inimigo.h"

class BigChief : public Inimigo
{
    private:
        short int forca;
        float distancia;
        float limiteDir;
        float limiteEsq;
        int direcao;
    public:
        BigChief(int id, sf::Vector2f pos, float dist);
        ~BigChief();
        void Mover();
        void Executar();
        void Salvar();
};
