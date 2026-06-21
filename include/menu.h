#pragma once
#include "ente.h"
#include "observador.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

namespace TheFrog{
    class Jogo;
}

namespace TheFrog{
    namespace Menus{
        class Menu : public Ente, public Observador
        {
            protected:
            std::vector<std::string> opcoesMenu;
            std::vector<sf::Text> botoesMenu;
            int opcaoIndice;
            int opcaoSelecionada;
            bool selecionado;
            bool ativo;
            sf::Font fonte;
            sf::Text textoTitulo;
            TheFrog::Jogo* pJog;
            
            public:
            Menu(int id, TheFrog::Jogo* jogo);
            virtual ~Menu();
            
            void InicializaBG();
            void InicializaBotoes();
            virtual void InicializaOpcoesMenu() = 0;
            virtual void PosicionaBotoes() = 0;
            virtual void InicializaTitulo() = 0;
            void DesenharBotoes();
            
            void Executar() override;
            void Notificar(sf::Event evento) override;
            
            int getOpcaoSelecionada() const;
            bool getSelecionado() const;
            void resetSelecionado();
            void setAtivo(bool estado);
        };
    }
}   