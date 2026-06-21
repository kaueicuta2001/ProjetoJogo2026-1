#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "observador.h"

namespace TheFrog{
    namespace Gerenciadores{
        class GerenciadorGrafico;
    }
}

namespace TheFrog{
    namespace Gerenciadores{
        class GerenciadorDeEventos {
        private:
            std::list<Observador*> observadores;
            static GerenciadorDeEventos* pGE;
            GerenciadorGrafico* pGG;
            bool capturandoInput;

            GerenciadorDeEventos(); 

        public:
            ~GerenciadorDeEventos();
            static GerenciadorDeEventos* getGerenciadorDeEventos();

            void Anexar(Observador* obs);
            void Desanexar(Observador* obs);
            void Executar();
        };
    }
}
