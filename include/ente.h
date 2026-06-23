#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace TheFrog{
    namespace Gerenciadores{
        class GerenciadorGrafico;
    }
}

namespace TheFrog{
    class Ente
    {
    protected:
        int id;
        static TheFrog::Gerenciadores::GerenciadorGrafico* pGG;
        sf::Texture textura;
        sf::Sprite sprite;
        sf::Vector2f posicao;
        sf::Vector2f tamanho;
        
    public:
        Ente(int id);
        Ente();
        virtual ~Ente();
        static void setGG(TheFrog::Gerenciadores::GerenciadorGrafico* gg);
        int getId() const;
        sf::Sprite& getSprite();
        void InicializarSprite(sf::Texture& textura);
        virtual void Executar() = 0;
        void Desenhar();
    };
}