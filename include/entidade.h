#pragma once
#include "Ente.h"

class Entidade : public Ente {
protected:
    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    sf::Color cor;

public:
    Entidade(int id, sf::Vector2f pos);
    virtual ~Entidade();
    virtual sf::Vector2f getPosicao() const;
    virtual sf::Vector2f getTamanho() const;
    virtual sf::Color getCor() const;
    virtual void setPosicao(sf::Vector2f pos);
    virtual void Executar() = 0;
    virtual void Salvar() = 0;
};