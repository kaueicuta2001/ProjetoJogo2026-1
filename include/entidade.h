#pragma once

#include "ente.h"

class Entidade : public Ente
{
    protected:
        sf::Vector2f posicao;
        sf::Vector2f tamanho;
        sf::RectangleShape corpo;
        sf::Color cor;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
