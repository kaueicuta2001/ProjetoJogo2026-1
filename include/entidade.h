#pragma once
#include "Ente.h"
#include <string>
#include <SFML/Graphics.hpp>

namespace TheFrog{
    namespace Entidades{
        class Entidade : public Ente
        {
            protected:
                bool vivo;
                sf::Vector2f vel;
                float gravidade;
                bool noChao;
                std::string nome;
                void salvarDataBuffer();
            public:
                Entidade(int id, sf::Vector2f pos);
                virtual ~Entidade();

                void setPosicao(sf::Vector2f pos);
                sf::Vector2f getPosicao() const;
                sf::Vector2f getTamanho() const;
                bool getVivo() const;
                void Desativar();
                
                void AplicarGravidade();
                void Gravitropismo();
                
                void SetNoChao(bool chao);
                bool getNoChao() const;
                std::string getNome() const;
                
                virtual void Executar() = 0;
                virtual void Salvar() = 0;
        };
    }
}