#pragma once

#include "entidade.h"

class Jogador;

class Chao : public Entidade
{
private:
    float altura;
    float largura;
    bool danoso;
public:
    Chao(int id, sf::Vector2f pos, bool danoso);
    ~Chao();
    void Executar();
    void Salvar();
};
