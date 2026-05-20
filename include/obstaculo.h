#pragma once

#include "entidade.h"

class Obstaculo : public Entidade
{
protected:
    bool danoso;
public:
    Obstaculo(bool danoso, int x, int y, int id);
    ~Obstaculo();

    virtual void Executar() = 0;
    virtual void Salvar() = 0;
};
