#pragma once

#include "ente.h"
#include "gerenciadorgrafico.h"

class Entidade : public Ente
{
    protected:
        sf::Vector2f posicao;
        sf::Vector2f tamanho;
        sf::Color cor;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();
        virtual sf::Vector2f getPosicao();
        virtual sf::Vector2f getTamanho();
        virtual sf::Color getCor();
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
