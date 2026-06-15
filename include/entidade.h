#pragma once
#include "ente.h"
#include <SFML/Graphics.hpp>
#include <string>

class Entidade : public Ente
{
protected:
    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    bool vivo;
    std::string nome; 

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
    void InicializarSprite(sf::Texture& textura);
    
    std::string getNome() const { return nome; }
};