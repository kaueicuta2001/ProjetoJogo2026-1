#pragma once

#include "menu.h"

namespace TheFrog{
    namespace Menus{
        class MenuPrincipal : public Menu
        {
        private:
            std::string titulo;
            sf::Text textoTitulo;
        public:
            MenuPrincipal(int id, TheFrog::Jogo* jogo);
            ~MenuPrincipal();
            void InicializaOpcoesMenu();
            void InicializaTitulo();
            void PosicionaBotoes();
            void DesenharTitulo();
            void Executar();
        };
    }
}