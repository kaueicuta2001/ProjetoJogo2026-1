#pragma once

#include "inimigo.h"

class BigChief : public Inimigo
{
private:
    short int forca;

public:
    BigChief(int id, sf::Vector2f pos, int num_vidas, int nivel_maldade, short int poder);
    ~BigChief();
    void Mover();
    void Executar();
    void Salvar();
};
