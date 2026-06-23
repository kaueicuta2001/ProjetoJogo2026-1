#pragma once

#include "menu.h"

namespace TheFrog{
    namespace Menus{
        class MenuFase : public Menu
        {
            sf::Text textoFase;
        public:
            MenuFase(TheFrog::Jogo* jogo);
            ~MenuFase();
            void InicializaTextoFase();
            void InicializaOpcoesMenu();
            void PosicionaBotoes();
            void Executar();
        };
    }
}