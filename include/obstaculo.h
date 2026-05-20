#pragma once

#include "entidade.h"

class Obstaculo : public Entidade
{
protected:
    bool danoso;
public:
    Obstaculo(bool danoso, int x, int y, int id);
    ~Obstaculo();

    virtual void executar() = 0;
    virtual void salvar() = 0;
};
