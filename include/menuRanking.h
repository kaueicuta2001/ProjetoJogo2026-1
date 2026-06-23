#pragma once
#include "menu.h"
#include <string>

namespace TheFrog{
    namespace Menus{
        class MenuRanking : public Menu {
        private:
            sf::Text textoFiltro;
            int estadoFiltro; 
        public:
            MenuRanking(TheFrog::Jogo* jogo);
            ~MenuRanking();
        
            void InicializaOpcoesMenu() override;
            void PosicionaBotoes() override;
            
            void Notificar(sf::Event evento) override; 
            void AtualizarRanking();
            void Executar() override;
        };
    }
}