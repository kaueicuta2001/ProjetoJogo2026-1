#pragma once

#include "inimigo.h"

class ReiBesouro : public Inimigo
{
    private:
        short int forca;
        float distancia;
        float limiteDir;
        float limiteEsq;
        int direcao;
    public:
        ReiBesouro(int id, sf::Vector2f pos, float dist);
        ~ReiBesouro();
        void Mover();
        void Executar();
        void Salvar();
};
