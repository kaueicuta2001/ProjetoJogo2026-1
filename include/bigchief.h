#pragma once

#include "inimigo.h"

class BigChief : public Inimigo
{
    private:
        short int forca;
    public:
        BigChief(int id, sf::Vector2f pos);
        ~BigChief();
        void Mover();
        void Executar();
        void Salvar();
};
