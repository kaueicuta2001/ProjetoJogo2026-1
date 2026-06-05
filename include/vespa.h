#pragma once

#include "inimigo.h"

class Vespa : public Inimigo
{
    private:
        float distancia;
        float limiteDir;
        float limiteEsq;
        int direcao;
    public:
        Vespa(int id, sf::Vector2f pos, float dist);
        ~Vespa();
        void Mover();
        void Executar();
        void Salvar();
};
