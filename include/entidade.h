#pragma once

#include "ente.h"
#include <string>

class Entidade : public Ente
{
protected:
    bool vivo;
    float gravidade;
    std::string nome;
    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    sf::Vector2f vel;

public:
    Entidade(int id, sf::Vector2f pos);
    virtual ~Entidade();

    virtual void Executar() = 0;
    virtual void Salvar() = 0;

    void setPosicao(sf::Vector2f pos);
    const sf::Vector2f getPosicao();
    const sf::Vector2f getTamanho();
    bool getVivo() const;
    void Desativar();
    void AplicarGravidade();
    
    std::string getNome();
};