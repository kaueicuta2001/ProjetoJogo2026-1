#pragma once
#include "menu.h"
#include <string>

namespace TheFrog{
    namespace Menus{
        class MenuNome : public Menu {
        private:
            std::string nomeDigitado;
            sf::Text textoNome;
        
        public:
            MenuNome(TheFrog::Jogo* jogo);
            ~MenuNome();
        
            void InicializaOpcoesMenu() override;
            void PosicionaBotoes() override;
        
            void Notificar(sf::Event evento) override;
            void Executar() override;
        
            std::string getNomeDigitado() const;
            void resetNome();
        };
    }
}