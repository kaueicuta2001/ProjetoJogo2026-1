#pragma once

#include <SFML/Graphics.hpp>

namespace TheFrog{
    class Ente;
}

namespace TheFrog{
    namespace Entidades{
        class Entidade;
    }
}

namespace TheFrog{
    namespace Gerenciadores{
        class GerenciadorGrafico
        {
            private:
            sf::RenderWindow* window;
            static GerenciadorGrafico* pGG;
            bool vsyncAtivo;
            GerenciadorGrafico();
            
            public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getWindow();
            void LimpaJanela();
            void DesenharEnte(Ente* pEnte);
            void Renderizar();
            void FecharJanela();
            bool VerificaJanelaAberta() const;
            void setVsync(bool ativo);
        };
    }
}