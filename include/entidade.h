#pragma once
#include "Ente.h"

class Entidade : public Ente
{
    protected:
        sf::Vector2f posicao;
        sf::Vector2f tamanho;
        sf::Color cor;
        bool vivo;
    public:
        Entidade(int id, sf::Vector2f pos);
        virtual ~Entidade();
        virtual void setPosicao(sf::Vector2f pos);
        virtual sf::Vector2f getPosicao();
        virtual sf::Vector2f getTamanho();
        virtual sf::Color getCor();
        virtual bool getVivo();
        virtual void Desativar();
        virtual void Executar() = 0;
        virtual void Salvar() = 0;
};
