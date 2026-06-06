#pragma once

#include "inimigo.h"

class Jogador;

class Vespa : public Inimigo
{
    private:
        float angulo;             // Controlador do tempo/ângulo para a fórmula
        float velocidadeAngular;  // Velocidade do voo
        float amplitudeX;         // Largura do símbolo do infinito
        float amplitudeY;         // Altura do símbolo do infinito
        sf::Vector2f posInicial;  // Ponto de âncora central do voo
    public:
        Vespa(int id, sf::Vector2f pos, float dist);
        ~Vespa();
        void Mover();
        void Executar();
        void Salvar();
        
        // Métodos virtuais puros herdados de Inimigo
        void AprimorarMaldade();
        void Danificar(Jogador* pJogador);
};