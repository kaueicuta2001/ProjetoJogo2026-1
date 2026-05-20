#pragma once

#include "obstaculo.h"

class ObstMedio : public Obstaculo
{
private:
    float largura;

public:
    ObstMedio(float largura, bool danoso, int x, int y, int id);
    ~ObstMedio();
    void Executar();
    void Salvar();
};
