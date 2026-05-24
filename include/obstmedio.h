#pragma once

#include "obstaculo.h"

class ObstMedio : public Obstaculo
{
private:
    float largura;

public:
    ObstMedio(int id, sf::Vector2f pos, bool danoso, float largura);
    ~ObstMedio();
    void Executar();
    void Salvar();
};
