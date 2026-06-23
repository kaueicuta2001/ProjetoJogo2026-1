#pragma once

#include "menu.h"

namespace TheFrog{
    namespace Menus{
        class MenuPrincipal : public Menu
        {
        private:
            sf::Text textoSelecione;
        public:
            MenuPrincipal(TheFrog::Jogo* jogo);
            ~MenuPrincipal();
            void InicializaTextoSelecione();
            void InicializaOpcoesMenu();
            void PosicionaBotoes();
            void Executar();
        };
    }
}