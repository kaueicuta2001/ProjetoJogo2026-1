#pragma once

#include "menu.h"

namespace TheFrog{
    namespace Menus{
        class MenuFase : public Menu
        {
        private:
            std::string titulo;
            sf::Text textoTitulo;
        public:
            MenuFase(int id, TheFrog::Jogo* jogo);
            ~MenuFase();
            void InicializaOpcoesMenu();
            void InicializaTitulo();
            void PosicionaBotoes();
            void DesenharTitulo();
            void Executar();
        };
    }
}